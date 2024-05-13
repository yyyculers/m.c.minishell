NAME = minishell
CC = CC
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR) -I$(shell brew --prefix readline)/include
INCLUDES_DIR = ./includes
BUILTIN_DIR = ./srcs/built_in

SRCS = srcs/main.c \
	   srcs/minishell_split.c \
       $(BUILTIN_DIR)/chdir.c \
       $(BUILTIN_DIR)/exit.c \
	   $(BUILTIN_DIR)/pwd.c \
	   $(BUILTIN_DIR)/commands.c \
	   $(BUILTIN_DIR)/echo.c \
	   $(BUILTIN_DIR)/env.c \

OBJS = $(SRCS:%.c=%.o)

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline -L$(shell brew --prefix readline)/lib

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
