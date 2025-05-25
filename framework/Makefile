SRCS = srcs/clean_test.c \
       srcs/load_test.c \
       srcs/launch_test.c \
       srcs/util.c

NAME = libunit.a
LIBDIR = ../libft
LIB = $(LIBDIR)/libft.a

OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
AR = ar rc
CFLAGS = -Wall -Wextra -Werror -I./$(LIBDIR)

all: $(LIB) $(NAME)


nm: $(NAME)
	nm -u libunit.a | sort | uniq | grep -v ft_

$(LIB):
	make -C $(LIBDIR)

$(NAME): $(OBJS)
	$(AR) $@ $^
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
