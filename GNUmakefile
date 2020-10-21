CC = gcc
CFLAGS = -fPIC -c -Wall -std=c89 -g
LDFLAGS = -shared -g -std=c89

LDFLAGS_EXEC = -L.
LDLIBS = -limage -ldl

OBJ_DIR := tmp
SRC_DIR := src_image
HDR_DIR := include

SERIAL_SRC := src/serial.c
SERIAL_EXEC := serial

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
HDR = ${wildcard include/*.h}
LIBRARY = libimage.so

build: prebuild $(SRC) $(OBJ) $(LIBRARY)

prebuild:
	mkdir -p $(OBJ_DIR)

$(LIBRARY): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR)
	$(CC) $(CFLAGS) $< -o $@

$(SERIAL_EXEC): $(SERIAL_SRC) build
	$(CC) $(LDFLAGS_EXEC) $< -o $@ $(LDLIBS)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(LIBRARY) $(SERIAL_EXEC)