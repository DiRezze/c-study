CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = calculadora
SRCS = main.c ListaDinEncad.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c ListaDinEncad.h
	$(CC) $(CFLAGS) -c $< -o $@


run: all
	./$(TARGET)

clean:
	rm -f