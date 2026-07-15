CC = gcc
CFLAGS = -Wall -Werror -Wextra
HD_DIR = ../../build

TARGET_Q6 = $(HD_DIR)/Quest_6
TARGET_Q7 = $(HD_DIR)/Quest_7
TARGET_Q8 = $(HD_DIR)/Quest_8

SRC = s21_string.c s21_string_test.c
OBJ = $(SRC:.c=.o)

all: strlen_tests

strlen_tests: $(OBJ)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET_Q6)

strcmp_tests: $(OBJ)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET_Q7)

strcpy: $(OBJ)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET_Q8)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -rf $(HD_DIR)

rebuild: clean strcpy

.PHONY: all strlen_tests strcmp_tests strcpy clean rebuild
