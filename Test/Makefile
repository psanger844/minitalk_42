NAME_CLIENT = client
NAME_SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# LDFLAGS = -lm -lrt
SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

.PHONY: all clean fclean re client server

all: client server

client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

server: $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER) $(LDFLAGS)

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all
