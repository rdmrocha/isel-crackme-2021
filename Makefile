CXX		  := clang++
CXX_FLAGS := -Wall -Wextra -std=c++17

BIN		:= bin
SRC		:= src

EXECUTABLE	:= crackme


all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	-mkdir -p $(BIN)
	$(CXX) $(CXX_FLAGS) $^ -o $@

clean:
	-rm $(BIN)/$(EXECUTABLE)