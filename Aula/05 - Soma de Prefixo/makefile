# Set the number of OpenMP threads
OMP_NUM_THREADS=4
export OMP_NUM_THREADS

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -fopenmp -lm -Wall -O2

# Target executable
TARGET = ./main.exe

# Source files
SRCS = ./src/menor_elem.c ./src/alg_seq.c ./src/soma_paral.c ./main.c

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET):
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS)

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: 
	all clean