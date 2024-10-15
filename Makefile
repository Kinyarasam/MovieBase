# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -Iinclude -I/usr/local/Cellar/postgresql@16/16.4/include -g

# Database library
LIBS = -L/usr/local/Cellar/postgresql@16/16.4/lib -lpq

# Source files
SRC = src/*.c

# Output executable name
TARGET = moviebase

# Build rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

# Clean rule
clean:
	rm -f $(TARGET)

.PHONY: all clean
