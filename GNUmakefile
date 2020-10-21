ifndef IMAGE_FILTER_DIR
IMAGE_FILTER_DIR := .
endif

CC := gcc
CFLAGS := -fPIC -c -Wall -g -std=c89
LDFLAGS := -shared -g -std=c89

OBJ_DIR := $(IMAGE_FILTER_DIR)/tmp
SRC_DIR := $(IMAGE_FILTER_DIR)/src
HDR_DIR := $(IMAGE_FILTER_DIR)/include

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
HDR := ${wildcard $(HDR_DIR)/*.h}
LIB := $(IMAGE_FILTER_DIR)/libimage.so
SLB := $(IMAGE_FILTER_DIR)/libimage.a

build: prebuild $(LIB) $(SLB)

$(LIB): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(SLB): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean prebuild
clean:
	rm -rf $(OBJ_DIR) $(LIB) $(SLB)

prebuild:
	mkdir -p $(OBJ_DIR)