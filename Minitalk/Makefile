NAME_CLIENT = client
NAME_SERVER = server
CC = cc
# CFLAGS = -Wall -Wextra -Werror
SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

SUBDIR = LIBFT

.PHONY: all clean fclean re client server

all: client server

client: $(SUBDIR) $(OBJS_CLIENT)
	@$(MAKE) -C $(SUBDIR)
	@$(CC) $(OBJS_CLIENT) -L$(SUBDIR) -lft -o $(NAME_CLIENT)

server: $(SUBDIR) $(OBJS_SERVER)
	@$(MAKE) -C $(SUBDIR)
	@$(CC) $(OBJS_SERVER) -L$(SUBDIR) -lft -o $(NAME_SERVER)

$(SUBDIR):
	@$(MAKE) -C $(SUBDIR)

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	@$(MAKE) -C $(SUBDIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -C $(SUBDIR) fclean

re: fclean all

