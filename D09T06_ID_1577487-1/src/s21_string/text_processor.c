#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int s21_streq(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return s1[i] == s2[i];
}

int main(int argc, char *argv[]) {
    if (argc != 2 || !s21_streq(argv[1], "-w")) {
        printf("n/a\n");
        return 0;
    }

    int width = 0;
    if (scanf("%d", &width) != 1 || width <= 1) {
        printf("n/a\n");
        return 0;
    }

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n');

    char text[200];
    int len = 0;
    while (len < 199 && (ch = getchar()) != EOF && ch != '\n') {
        text[len++] = (char)ch;
    }
    text[len] = '\0';

    if (len == 0) {
        printf("n/a\n");
        return 0;
    }

    int i = 0;
    int current_line_len = 0;
    int is_first_line = 1;

    while (i < len) {
        if (current_line_len == 0 && (text[i] == ' ' || text[i] == '\t')) {
            i++;
            continue;
        }

        int word_len = 0;
        while (i + word_len < len && text[i + word_len] != ' ' && text[i + word_len] != '\t') {
            word_len++;
        }

        if (word_len > 0) {
            if (current_line_len + (current_line_len > 0 ? 1 : 0) + word_len <= width) {
                if (current_line_len > 0) {
                    printf(" ");
                    current_line_len++;
                } else {
                    if (!is_first_line) {
                        printf("\n");
                    }
                    is_first_line = 0;
                }
                for (int j = 0; j < word_len; j++) {
                    printf("%c", text[i + j]);
                }
                current_line_len += word_len;
                i += word_len;
            } else if (word_len <= width) {
                if (!is_first_line) {
                    printf("\n");
                }
                is_first_line = 0;
                for (int j = 0; j < word_len; j++) {
                    printf("%c", text[i + j]);
                }
                current_line_len = word_len;
                i += word_len;
            } else {
                int space_left = width - current_line_len - (current_line_len > 0 ? 1 : 0);
                if (space_left >= 2) {
                    if (current_line_len > 0) {
                        printf(" ");
                    } else {
                        if (!is_first_line) {
                            printf("\n");
                        }
                        is_first_line = 0;
                    }
                    for (int j = 0; j < space_left - 1; j++) {
                        printf("%c", text[i++]);
                        word_len--;
                    }
                    printf("-");
                    current_line_len = 0;
                } else {
                    if (current_line_len > 0) {
                        current_line_len = 0;
                    }
                }

                while (word_len > width) {
                    if (!is_first_line) {
                        printf("\n");
                    }
                    is_first_line = 0;
                    for (int j = 0; j < width - 1; j++) {
                        printf("%c", text[i++]);
                        word_len--;
                    }
                    printf("-");
                }

                if (word_len > 0) {
                    if (!is_first_line) {
                        printf("\n");
                    }
                    is_first_line = 0;
                    for (int j = 0; j < word_len; j++) {
                        printf("%c", text[i++]);
                    }
                    current_line_len = word_len;
                }
            }
        } else {
            i++;
        }
    }
    printf("\n");

    return 0;
}
