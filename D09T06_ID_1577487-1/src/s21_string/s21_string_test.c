#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

void s21_strlen_test(const char *test_input, int expected_output) {
    int result = s21_strlen(test_input);
    printf("INPUT: \"%s\" | EXPECTED: %d | GOT: %d | ", test_input, expected_output, result);
    if (result == expected_output)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcmp_test(const char *str1, const char *str2, int expected_sign) {
    int result = s21_strcmp(str1, str2);
    int result_sign = (result > 0) - (result < 0);
    printf("INPUT: \"%s\" vs \"%s\" | EXPECTED SIGN: %d | GOT SIGN: %d | ", str1, str2, expected_sign,
           result_sign);
    if (result_sign == expected_sign)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcpy_test(char *dest, const char *src, const char *expected) {
    printf("INPUT SRC: \"%s\" | ", src);
    s21_strcpy(dest, src);
    printf("GOT DEST: \"%s\" | ", dest);
    if (s21_strcmp(dest, expected) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcat_test(char *dest, const char *src, const char *expected) {
    printf("INPUT SRC: \"%s\" | ", src);
    s21_strcat(dest, src);
    printf("GOT DEST: \"%s\" | ", dest);
    if (s21_strcmp(dest, expected) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strchr_test(char *str, int ch, int expected_offset, int is_null) {
    char *result = s21_strchr(str, ch);
    printf("INPUT: \"%s\", '%c' | ", str, ch == '\0' ? '0' : ch);

    if (is_null) {
        printf("EXPECTED: NULL | GOT: %s | ", result == NULL ? "NULL" : "NOT NULL");
        if (result == NULL)
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    } else {
        char *expected_ptr = str + expected_offset;
        printf("EXPECTED OFFSET: %d | GOT OFFSET: %ld | ", expected_offset, result - str);
        if (result == expected_ptr)
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    }
}

void s21_strstr_test(const char *haystack, const char *needle, int expected_offset, int is_null) {
    char *result = s21_strstr(haystack, needle);
    printf("INPUT: \"%s\" vs \"%s\" | ", haystack, needle);

    if (is_null) {
        printf("EXPECTED: NULL | GOT: %s | ", result == NULL ? "NULL" : "NOT NULL");
        if (result == NULL)
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    } else {
        char *expected_ptr = (char *)(haystack + expected_offset);
        printf("EXPECTED OFFSET: %d | GOT OFFSET: %ld | ", expected_offset, result - haystack);
        if (result == expected_ptr)
            printf("SUCCESS\n");
        else
            printf("FAIL\n");
    }
}

int main(void) {
    printf("=== STRLEN TESTS ===\n");
    s21_strlen_test("Hello", 5);
    s21_strlen_test("", 0);
    s21_strlen_test("   ", 3);

    printf("\n=== STRCMP TESTS ===\n");
    s21_strcmp_test("Hello", "Hello", 0);
    s21_strcmp_test("Apple", "Banana", -1);
    s21_strcmp_test("Banana", "Apple", 1);

    printf("\n=== STRCPY TESTS ===\n");
    char b1[] = "XXXXXXXXXXXXX";
    s21_strcpy_test(b1, "Hello", "Hello");
    char b2[] = "XXXXXXXXXXXXX";
    s21_strcpy_test(b2, "", "");
    char b3[] = "XXXXXXXXXXXXX";
    s21_strcpy_test(b3, "A\nB", "A\nB");

    printf("\n=== STRCAT TESTS ===\n");
    char b4[50] = "Hello";
    s21_strcat_test(b4, ", World!", "Hello, World!");
    char b5[50] = "Hello";
    s21_strcat_test(b5, "", "Hello");
    char b6[50] = "";
    s21_strcat_test(b6, "Solo", "Solo");

    printf("\n=== STRCHR TESTS ===\n");
    char s1[] = "School21";
    s21_strchr_test(s1, 'o', 4, 0);
    char s2[] = "School21";
    s21_strchr_test(s2, 'z', 0, 1);
    char s3[] = "School21";
    s21_strchr_test(s3, '\0', 8, 0);

    printf("\n=== STRSTR TESTS ===\n");
    s21_strstr_test("Hello, World!", "World", 7, 0);
    s21_strstr_test("Hello, World!", "Apple", 0, 1);
    s21_strstr_test("Hello, World!", "", 0, 0);

    return 0;
}
