CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = mysh
SRC = src/main.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

