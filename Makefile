# Makefile for image sampling program using OpenCV

# Compiler and flags
CXX = g++
CXXFLAGS = `pkg-config --cflags opencv4` -Wall -O2

# Libraries
LDFLAGS = `pkg-config --libs opencv4`

# Target executable
TARGET = sample

# Source files
SRC = main.cpp process.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Rule to create object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild the project
rebuild: clean all

