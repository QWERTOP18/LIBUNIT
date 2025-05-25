SRCS := $(shell find . -name "*.c")


NAME = test.out
LIBDIR = ../libft
LIB = $(LIBDIR)/libft.a
FRAMEDIR = ../framework
FRAME = $(FRAMEDIR)/libunit.a

OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror \
 	-I./$(LIBDIR)/ \
	-I./$(FRAMEDIR)/srcs \
	-I ./srcs

all: $(LIB) $(FRAME) $(NAME)

$(LIB):
	make -C $(LIBDIR)
$(FRAME):
	make -C $(FRAMEDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(FRAME) $(LIB)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

test: all
	./$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
