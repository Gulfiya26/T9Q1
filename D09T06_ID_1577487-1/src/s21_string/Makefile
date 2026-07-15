CC = gcc
CFLAGS = -Wall -Werror -Wextra
HD_DIR = ../../build

TARGET_Q6  = $(HD_DIR)/Quest_6
TARGET_Q7  = $(HD_DIR)/Quest_7
TARGET_Q8  = $(HD_DIR)/Quest_8
TARGET_Q9  = $(HD_DIR)/Quest_9
TARGET_Q10 = $(HD_DIR)/Quest_10
TARGET_Q11 = $(HD_DIR)/Quest_11
TARGET_Q12 = $(HD_DIR)/Quest_12
TARGET_Q13 = $(HD_DIR)/Quest_13

SRC_TESTS = s21_string.c s21_string_test.c
OBJ_TESTS = $(SRC_TESTS:.c=.o)

all: strlen_tests

strlen_tests: $(OBJ_TESTS)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ_TESTS) -o $(TARGET_Q6)

strcmp_tests: $(OBJ_TESTS)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ_TESTS) -o $(TARGET_Q7)

strcpy: $(OBJ_TESTS)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ_TESTS) -o $(TARGET_Q8)

strcat: $(OBJ_TESTS)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ_TESTS) -o $(TARGET_Q9)

strchr: $(OBJ_TESTS)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ_TESTS) -o $(TARGET_Q10)

strstr: $(OBJ_TESTS)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ_TESTS) -o $(TARGET_Q11)

full_coverage_tests: $(OBJ_TESTS)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ_TESTS) -o $(TARGET_Q12)

text_processor: text_processor.c s21_string.c
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) text_processor.c s21_string.c -o $(TARGET_Q13)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -rf $(HD_DIR)

rebuild: clean text_processor

.PHONY: all strlen_tests strcmp_tests strcpy strcat strchr strstr full_coverage_tests text_processor clean rebuild
