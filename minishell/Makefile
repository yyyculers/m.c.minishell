NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = inc

SRCS = srcs/main.c \
	   srcs/minishell_split.c \
       srcs/commands.c \
       srcs/builtin/chdir.c \
       srcs/builtin/exit.c \
	   srcs/builtin/pwd.c \

OBJS = $(SRCS:.c=.o)

LIBFTDIR = srcs/libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -lreadline

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
