#include "s21_string.h"

#include <stdlib.h>

int s21_strlen(const char *str) {
    int length = 0;
    if (str != NULL) {
        while (str[length] != '\0') {
            length++;
        }
    }
    return length;
}

int s21_strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

char *s21_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *s21_strcat(char *dest, const char *src) {
    int i = 0;
    int j = 0;
    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

char *s21_strchr(char *str, int ch) {
    while (*str != '\0') {
        if (*str == (char)ch) {
            return str;
        }
        str++;
    }
    if ((char)ch == '\0') {
        return str;
    }
    return NULL;
}

char *s21_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack;
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*h != '\0' && *n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack;
        }

        haystack++;
    }

    return NULL;
}
