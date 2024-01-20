package org.example.chapter5;

import java.util.*;
import java.util.stream.Collectors;

public class Practice {
    public static void main(String[] args) {
        Trader raoul = new Trader("Raoul", "Cambridge");
        Trader mario = new Trader("Mario", "Milan");
        Trader alan = new Trader("Alan", "Cambridge");
        Trader brian = new Trader("Brian", "Cambridge");

        List<Transaction> transactions = Arrays.asList(
                new Transaction(brian, 2011, 300),
                new Transaction(raoul, 2012, 1000),
                new Transaction(raoul, 2011, 400),
                new Transaction(mario, 2012, 710),
                new Transaction(mario, 2012, 700),
                new Transaction(alan, 2012, 950)
        );
        // 2011년에 일어난 모든 트랜잭션을 찾아 값을 오름차순으로 정리하시오.
        // 내 풀이
        List<Integer> l1 = transactions.stream()
                .filter((transaction -> transaction.getYear() == 2011))
                .map(Transaction::getValue)
                .sorted()
                .collect(Collectors.toList());
        System.out.println(l1);

        // 책 풀이
        List<Transaction> l11 = transactions.stream()
                .filter((transaction -> transaction.getYear() == 2011))
                .sorted(Comparator.comparing(Transaction::getValue))
                .collect(Collectors.toList());
        System.out.println(l11);

        // 거래자가 근무하는 모든 도시를 중복 없이 나열하시오.
        // 내 풀이, 책 풀이
        List<String> l2 = transactions.stream()
                .map(transaction -> transaction.getTrader().getCity())
                .distinct()
                .collect(Collectors.toList());
        System.out.println(l2);

        // 모든 거래자의 이름을 알파벳순으로 정렬해서 반환하시오.
        // 내 풀이
        System.out.println("\n모든 거래자의 이름을 알파벳순으로 정렬해서 반환하시오.");
        List<String> l3 = transactions.stream()
                .map(transaction -> transaction.getTrader().getName())
                .distinct()
                .sorted()
                .collect(Collectors.toList());
        System.out.println(l3);

        // 책 풀이
        String l33 = transactions.stream()
                .map(transaction -> transaction.getTrader().getName())
                .distinct()
                .sorted()
                .reduce("", (n1, n2) -> n1 + n2);
        System.out.println(l33);


        // 밀라노에 거래자가 있는가?
        // 내 풀이, 자바에서 문자열은 equals로 비교한다. 일단 여기선 true 잘 나옴.
        System.out.println("\n밀라노에 거래자가 있는가?");
        boolean l4 = transactions.stream()
                .anyMatch(transaction -> transaction.getTrader().getCity() == "Milan");
        System.out.println(l4);

        // 책 풀이
        boolean l44 = transactions.stream()
                .anyMatch(transaction -> transaction.getTrader().getCity().equals("Milan"));
        System.out.println(l44);



        // 케임브리지에 거주하는 거래자의 모든 트랜잭션 값을 출력하시오.
        // 내 풀이
        System.out.println("\n케임브리지에 거주하는 거래자의 모든 트랜잭션 값을 출력하시오.");
        List<Integer> l5 = transactions.stream()
                .filter(transaction -> transaction.getTrader().getCity() == "Cambridge")
                .map(transaction -> transaction.getValue())
                .collect(Collectors.toList());
        System.out.println(l5);

        // 책 풀이
        transactions.stream()
                .filter(transaction -> transaction.getTrader().getCity().equals("Cambridge"))
                .map(Transaction::getValue)
                .forEach(System.out::println);

        // 전체 트랜잭션중 최댓값은 얼마인가?
        // 내 풀이, 책풀이
        System.out.println("\n전체 트랜잭션중 최댓값은 얼마인가?");
        Optional<Integer> l6 = transactions.stream()
                .map(Transaction::getValue)
                .reduce(Integer::max);
        System.out.println(l6.get());

        // 전체 트랜잭션중 최솟값은 얼마인가?
        // 내 풀이
        System.out.println("\n전체 트랜잭션중 최솟값은 얼마인가?");
        Optional<Integer> l7 = transactions.stream()
                .map(Transaction::getValue)
                .reduce(Integer::min);
        System.out.println(l7.get());

        // 책 풀이
        Optional<Transaction> l77 = transactions.stream()
                .reduce((t1, t2) -> t1.getValue() < t2.getValue() ? t1 : t2);
        System.out.println(l77.get());
    }

}

class Trader {
    private final String name;
    private final String city;

    public Trader(String name, String city) {
        this.name = name;
        this.city = city;
    }

    public String getName() {
        return name;
    }

    public String getCity() {
        return city;
    }

    public String toString() {
        return "Trader:" + this.name + " in " + this.city;
    }
}

class Transaction {
    private final Trader trader;
    private final int year;
    private final int value;

    public Transaction(Trader trader, int year, int value) {
        this.trader = trader;
        this.year = year;
        this.value = value;
    }

    public Trader getTrader() {
        return trader;
    }

    public int getYear() {
        return year;
    }

    public int getValue() {
        return value;
    }

    public String toString() {
        return "{" + this.trader + ", " +
                "year: " + this.year + ", " +
                "value: " + this.value + "}";
    }
}
