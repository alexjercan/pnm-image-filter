CC = gcc
CFLAGS = -fPIC -c -Wall -std=c89 -g
LDFLAGS = -shared -g -std=c89

LDFLAGS_EXEC = -L.
LDLIBS = -limage -ldl

OBJ_DIR := tmp
SRC_DIR := src
HDR_DIR := include

SERIAL_DIR := serial
SERIAL_SRC := $(SERIAL_DIR)/serial.c
SERIAL_OBJ := $(SERIAL_DIR)/serial.o
SERIAL_EXEC := exec_serial

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
HDR = ${wildcard include/*.h}
LIBRARY = libimage.so

build: prebuild $(SRC) $(OBJ) $(LIBRARY) postbuild

postbuild:
	cp $(LIBRARY) $(SERIAL_DIR)/$(LIBRARY)

prebuild:
	mkdir -p $(OBJ_DIR)

$(LIBRARY): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR)
	$(CC) $(CFLAGS) $< -o $@

$(SERIAL_EXEC): $(SERIAL_OBJ) build
	$(CC) $(LDFLAGS_EXEC) $< -o $@ $(LDLIBS)

$(SERIAL_OBJ): $(SERIAL_SRC)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(LIBRARY)