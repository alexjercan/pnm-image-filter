CC = gcc
CFLAGS = -c -Wall -std=c89 -g
LDFLAGS = -g -std=c89

OBJ_DIR := tmp
SRC_DIR := src
HDR_DIR := include

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
HDR := ${wildcard $(HDR_DIR)/*.h}
EXEC := main

build: prebuild $(SRC) $(OBJ) $(EXEC)

prebuild:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR)
	$(CC) $(CFLAGS) $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(EXEC)