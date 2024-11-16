# 編譯器
CC = gcc
# 編譯選項
CFLAGS = -Wall -g

# 目標程序
TARGET = program

# 源文件
SRCS = main.c list.c ui.c
# 目標文件
OBJS = main.o list.o ui.o

# 編譯最終目標
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 編譯每個 .c 為 .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
clean:
	rm -f $(TARGET) $(OBJS)
