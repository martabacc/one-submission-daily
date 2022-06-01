package com.mycompany.domain;

import java.util.*;

public class IsPalindrome {
    public static boolean check(String input) {
        int length = input.length();
        if (length == 1) return true;
        if (length == 2) return input.charAt(0) == input.charAt(1);

        boolean isCurrentEndAndLastIndexIdentical = input.charAt(0) == input.charAt(length - 1);

        return isCurrentEndAndLastIndexIdentical
                ? IsPalindrome.check(input.substring(1, length - 1))
                : false;
    }
}