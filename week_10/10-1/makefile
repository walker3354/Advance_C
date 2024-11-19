
CC = gcc

CFLAGS = -Wall -g

TARGET = program

SRCS = main.c list.c ui.c

OBJS = main.o list.o ui.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
