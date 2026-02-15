# Compiler
CC := g++

CFLAGS_RELEASE := -Wall -Wextra -O3
CFLAGS_DEBUG := -Wall -Wextra -g

ifeq ($(OS), Windows_NT)
	LIBRARY_PATHS := -L lib/windows
	LDFLAGS := -lraylib -lgdi32 -lwinmm
	TARGET_DIR := build/windows
else
	# Linux
	LIBRARY_PATHS :=-L./lib/linux
	LDFLAGS := ./lib/linux/libraylib.a -lGL -lm -lpthread -ldl -lrt -lX11
	TARGET_DIR := build/linux
endif

INCLUDES := -I./include
SRC_DIR := src
OBJ_DIR := obj
TARGET := main

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: release

release: CFLAGS := $(CFLAGS_RELEASE)
release: $(TARGET)

debug: CFLAGS := $(CFLAGS_DEBUG)
debug: $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJS) | $(TARGET_DIR)
	$(CC) $(CFLAGS) $(LIBRARY_PATHS) $^ -o $(TARGET_DIR)/$@ $(LDFLAGS)

clean:
ifeq ($(OS),Windows_NT)
	@rmdir /S /Q $(OBJ_DIR) 2>NUL || exit 0
	@rmdir /S /Q build 2>NUL || exit 0
else
	rm -rf $(OBJ_DIR) build
endif

bear: clean
	@bear -- make -n > /dev/null || true
	@bear -- make

.PHONY: all release debug clean bear
