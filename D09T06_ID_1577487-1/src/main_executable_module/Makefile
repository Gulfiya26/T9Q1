CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -lm

UNAME_S := $(shell uname -s)
HD_DIR = ../../build

ifeq ($(UNAME_S), Linux)
    DYLIB_FLAGS = -shared -fPIC
    RPATH_FLAGS = -Wl,-rpath,$(HD_DIR)
endif
ifeq ($(UNAME_S), Darwin)
    DYLIB_FLAGS = -dynamiclib -current_version 1.0 -compatibility_version 1.0 -fPIC
    RPATH_FLAGS = -Wl,-rpath,@executable_path/
endif

TARGET_Q3 = $(HD_DIR)/Quest_3
TARGET_Q4 = $(HD_DIR)/Quest_4
TARGET_Q5 = $(HD_DIR)/Quest_5
DYLIB_TARGET = $(HD_DIR)/data_process.so

SRC_Q5 = main_executable_module.c \
         ../data_libs/data_io.c \
         ../data_libs/data_stat.c \
         ../yet_another_decision_module/decision.c

OBJ_Q5 = $(SRC_Q5:.c=.o)

SRC_Q3 = main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c
OBJ_Q3 = $(SRC_Q3:.c=.o)
SRC_Q4 = main_executable_module.c ../data_libs/data_io.c ../data_module/data_process.c ../yet_another_decision_module/decision.c
OBJ_Q4 = $(SRC_Q4:.c=.o)

all: $(TARGET_Q3)

$(TARGET_Q3): $(OBJ_Q3)
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ_Q3) -o $(TARGET_Q3) $(LIBS)

data_stat.a: ../data_libs/data_stat.o
	ar rcs data_stat.a ../data_libs/data_stat.o

build_with_static: $(OBJ_Q4) data_stat.a
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(OBJ_Q4) data_stat.a -o $(TARGET_Q4) $(LIBS)


data_process.so: ../data_module/data_process.c
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) $(DYLIB_FLAGS) ../data_module/data_process.c ../data_libs/data_stat.c -o $(DYLIB_TARGET)

build_with_dynamic: $(OBJ_Q5) data_process.so
	mkdir -p $(HD_DIR)
	$(CC) $(CFLAGS) -DDYNAMIC $(OBJ_Q5) $(DYLIB_TARGET) -o $(TARGET_Q5) $(LIBS) $(RPATH_FLAGS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -DDYNAMIC -c main_executable_module.c -o main_executable_module.o

clean:
	rm -f *.o ../data_libs/*.o ../data_module/*.o ../yet_another_decision_module/*.o data_stat.a libdata_stat.a
	rm -rf $(HD_DIR)

rebuild: clean all

.PHONY: all clean rebuild data_stat.a build_with_static data_process.so build_with_dynamic
