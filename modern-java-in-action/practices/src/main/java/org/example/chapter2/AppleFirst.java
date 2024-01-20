package org.example.chapter2;

import java.util.ArrayList;
import java.util.List;

public class AppleFirst {

    public static void prettyPrintApple(List<Apple> inventory, ApplePrint applePrint) {
        for(Apple apple: inventory) {
            System.out.println(applePrint.accept(apple));
        }
    }

    // 퀴즈 2-1 유연한 prettyPrintApple 메서드 구현하기
    // 동작 파라미터화(Behavior Parameterization): 어떻게 실행할지 결정하지 않은 코드 블럭을 말한다.
    public static void main(String[] args) {
        List<Apple> apples = new ArrayList<>();

        apples.add(new Apple(100));
        apples.add(new Apple(150));
        apples.add(new Apple(200));

        // 인터페이스를 사용해 다양한 출력방식을 선택할 수 있다.
        prettyPrintApple(apples, new AppleSimplePrint());
        prettyPrintApple(apples, new AppleTextPrint());
    }
}

interface ApplePrint {
    String accept(Apple a);
}

class AppleSimplePrint implements ApplePrint {
    public String accept(Apple apple) {
        return "weight: " + apple.getWeight() + "g";
    }
}

class AppleTextPrint implements ApplePrint {
    public String accept(Apple apple) {
        String text = apple.getWeight() > 150 ? "heavy" : "light";
        return "this apple is " + text;
    }
}