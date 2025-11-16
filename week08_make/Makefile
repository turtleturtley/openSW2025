
CC = gcc
CFLAGS = -Wall -Iinclude
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib

LIB_NAME = libmybasic.a
LIB = $(LIB_DIR)/$(LIB_NAME)
APP = $(BIN_DIR)/myapp

SRCS = $(SRC_DIR)/add.c $(SRC_DIR)/sub.c $(SRC_DIR)/mul.c $(SRC_DIR)/div.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: basic $(APP)

basic: $(OBJS)
	mkdir -p $(LIB_DIR)
	ar rcs $(LIB) $(OBJS)

$(APP): $(OBJ_DIR)/myapp.o $(LIB)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(APP) $(OBJ_DIR)/myapp.o -L$(LIB_DIR) -lmybasic

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)

.PHONY: all basic clean
