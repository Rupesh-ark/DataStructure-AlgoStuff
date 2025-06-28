CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iincludes
SRC_DIR = problems
BIN_DIR = bin

# Auto-generate executables for all .cpp files in problems/
SRCS = $(wildcard $(SRC_DIR)/**/*.cpp)
EXES = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%, $(SRCS))

.PHONY: all clean

all: $(EXES)

$(BIN_DIR)/%: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)


run:
	@echo "Usage: make run FILE=arrays/two_sum"

run-%:
	./bin/$* < input/$*.txt > output/$*.txt


clean:
	rm -rf $(BIN_DIR)


