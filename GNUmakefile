ifndef IMAGE_FILTER_DIR
IMAGE_FILTER_DIR := .
endif

AR := ar
CC := gcc
CFLAGS := -fPIC -c -Wall -g
LDFLAGS := -shared -g
LSFLAGS := rcs

OBJ_DIR := $(IMAGE_FILTER_DIR)/tmp
SRC_DIR := $(IMAGE_FILTER_DIR)/src
HDR_DIR := $(IMAGE_FILTER_DIR)/include

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
HDR := ${wildcard $(HDR_DIR)/*.h}
DLL := ${IMAGE_FILTER_DIR}/libimage.so
LIB := $(IMAGE_FILTER_DIR)/libimage.a

build: prebuild $(LIB)

$(LIB): $(OBJ)
	$(AR) $(LSFLAGS) $@ $^

$(DLL): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean prebuild
clean:
	rm -rf $(OBJ_DIR) $(LIB) $(DLL)

prebuild:
	mkdir -p $(OBJ_DIR)