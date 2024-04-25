SRCS = 	ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memset.c \
 		ft_strncmp.c \
 		ft_memcpy.c \
 		ft_memchr.c \
 		ft_memmove.c \
 		ft_memcmp.c \
 		ft_atoi.c \
 		ft_isalpha.c \
 		ft_isdigit.c \
 		ft_isalnum.c \
 		ft_isascii.c \
 		ft_isprint.c \
		ft_isspace.c \
 		ft_toupper.c \
 		ft_tolower.c \
		ft_calloc.c \
		ft_substr.c \
		ft_bzero.c \
		ft_strdup.c \
		ft_strnstr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c\
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
B_SRCS=	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
	 	ft_lstdelone.c \
	 	ft_lstclear.c \
	 	ft_lstiter.c \
	 	ft_lstmap.c

SRCS += ft_printf/ft_putchar.c \
	ft_printf/ft_putnbr.c \
	ft_printf/ft_putstr.c \
	ft_printf/ft_printchar.c \
	ft_printf/ft_print_int.c \
	ft_printf/ft_print_uint.c \
	ft_printf/ft_printstring.c \
	ft_printf/ft_print_address.c \
	ft_printf/ft_print_lowerhexa.c \
	ft_printf/ft_print_upperhexa.c \
	ft_printf/ft_printf.c \

OBJS += ft_printf/ft_putchar.o \
	ft_printf/ft_putnbr.o \
	ft_printf/ft_putstr.o \
	ft_printf/ft_printchar.o \
	ft_printf/ft_print_int.o \
	ft_printf/ft_print_uint.o \
	ft_printf/ft_printstring.o \
	ft_printf/ft_print_address.o \
	ft_printf/ft_print_lowerhexa.o \
	ft_printf/ft_print_upperhexa.o \
	ft_printf.o \


OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
NAME = libft.a
LIBC = ar rc
LIBR = ranlib
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I$(INCL)

INCL = libft.h
INCL += -I ft_printf/ft_printf.h

ifdef WITH_BONUS
	OBJS += $(B_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $@ $(OBJS)
	$(LIBR) $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_OBJS)

bonus:
	make WITH_BONUS=1

re: fclean all