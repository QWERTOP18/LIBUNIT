SRCS := $(addprefix example/, \
		00_launcher_example.c \
		01_basic.c \
		02_segv.c \
		03_bus.c \
		04_ok.c \
		05_ko.c \
		06_timeout.c \
		07_abort.c \
		08_fpe.c \
		09_ill.c \
		10_pipe.c \
		11_stdout.c \
	) \
	main.c


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
	-I./$(FRAMEDIR)/srcs

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
