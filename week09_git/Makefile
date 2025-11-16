CC = gcc
CFLAGS = -Iinclude -fPIC

SRC = src
OBJ = obj
BIN = bin
LIB = lib

OPS = myadd mysub mymul mydiv mymod mypow
OPS_OBJ = $(patsubst %, $(OBJ)/%.o, $(OPS))

APP = $(OBJ)/myapp.o
SHARED = $(LIB)/libmyops.so.1.0

all: $(SHARED) $(BIN)/myapp

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SHARED): $(OPS_OBJ)
	$(CC) -shared -o $@ $^
	ln -sf libmyops.so.1.0 $(LIB)/libmyops.so

$(BIN)/myapp: $(APP) $(SHARED)
	$(CC) -o $@ $(APP) -L$(LIB) -lmyops

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/myapp
	rm -f $(LIB)/libmyops.so*
