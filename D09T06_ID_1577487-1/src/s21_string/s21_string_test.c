#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test(const char *test_input, int expected_output) {
    int result = s21_strlen(test_input);
    printf("INPUT: \"%s\" | EXPECTED: %d | GOT: %d | ", test_input, expected_output, result);
    if (result == expected_output) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test(const char *str1, const char *str2, int expected_sign) {
    int result = s21_strcmp(str1, str2);
    int result_sign = (result > 0) - (result < 0);  // Получаем -1, 0 или 1

    printf("INPUT: \"%s\" vs \"%s\" | EXPECTED SIGN: %d | GOT SIGN: %d | ", str1, str2, expected_sign,
           result_sign);

    if (result_sign == expected_sign) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

int main(void) {
    printf("--- STRLEN TESTS ---\n");
    s21_strlen_test("Hello", 5);
    s21_strlen_test("", 0);
    s21_strlen_test("Symbol\0Hidden", 6);

    printf("\n--- STRCMP TESTS ---\n");

    s21_strcmp_test("Hello", "Hello", 0);
    s21_strcmp_test("Apple", "Banana", -1);
    s21_strcmp_test("Banana", "Apple", 1);

    s21_strcmp_test("", "", 0);
    s21_strcmp_test("Hello", "", 1);
    s21_strcmp_test("", "Hello", -1);

    s21_strcmp_test("Hello", "Hello ", -1);
    s21_strcmp_test("123", "124", -1);
    s21_strcmp_test("test", "Test", 1);

    return 0;
}
