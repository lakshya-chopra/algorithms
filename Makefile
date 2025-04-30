CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

SOURCES := $(wildcard *.cpp)
BIN_DIR := bin
EXECUTABLES := $(patsubst %.cpp,$(BIN_DIR)/%,$(SOURCES))

all: $(BIN_DIR) $(EXECUTABLES)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)
