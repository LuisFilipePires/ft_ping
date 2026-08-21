NAME = ft_ping

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes

SRC =	src/main.c \
		src/utils.c \
		src/parsing.c \
		src/send.c \
		src/receive.c \
		src/socket.c \
		src/checksum.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
