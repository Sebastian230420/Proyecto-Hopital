CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRC = src
OBJ = obj
BIN = hospital

SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS = $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)

all: dirs $(BIN)

dirs:
	mkdir -p $(OBJ)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ) $(BIN)
