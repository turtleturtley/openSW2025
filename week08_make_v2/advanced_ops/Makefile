PROJ=..
SRC_DIR=$(PROJ)/advanced_ops/src
OBJ_DIR=$(PROJ)/advanced_ops/obj
INC_DIR=$(PROJ)/include
LIB_DIR=$(PROJ)/lib

CC=gcc
CFLAGS=-I$(INC_DIR)
AR=ar
LIB=$(LIB_DIR)/libmyadvanced.a

SRCS=$(SRC_DIR)/mymod.c $(SRC_DIR)/mypow.c
OBJS=$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIB)

$(LIB): $(OBJS)
	mkdir -p $(LIB_DIR)
	$(AR) rcs $(LIB) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o
