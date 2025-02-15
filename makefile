# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -g -Wall -O2

# Target executable
PROG ?= main

# Object files
OBJS = ChessPiece.o Pawn.o Rook.o main.o

# Default target
all: $(PROG)

# Compile source files into object files
.cpp.o:
    $(CXX) $(CXXFLAGS) -c -o $@ $<

# Link object files to create the executable
$(PROG): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Clean up build files
clean:
    rm -rf *.o $(PROG)

# Rebuild the project
rebuild: clean all