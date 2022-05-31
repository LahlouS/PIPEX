CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=pipex
OBJ:=main.o\
tools.o\
tools_2.o\
ft_split.o\

INC=-I ./
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	gcc $(INC) $(CFLAGS) -c $< -o $@

.PHONY		: all clean fclean re

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(TARGET)

re: 
	rm -f $(OBJ) $(TARGET) && make all