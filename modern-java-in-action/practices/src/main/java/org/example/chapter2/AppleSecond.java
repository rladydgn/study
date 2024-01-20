package org.example.chapter2;

import java.util.ArrayList;
import java.util.List;

public class AppleSecond {

    public static <T> List<T> filter(List<T> list, Predicate<T> p) {
        List<T> result = new ArrayList<>();
        for(T e: list) {
            if(p.test(e)) {
                result.add(e);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        List<Apple> apples = new ArrayList<>();

        apples.add(new Apple(100));
        apples.add(new Apple(150));
        apples.add(new Apple(200));

        List<Apple> bigApples = filter(apples, (Apple apple) -> apple.getWeight() > 150);
        System.out.println(bigApples.size());
    }
}

interface Predicate<T> {
    boolean test(T t);
}
