NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -c

RM = rm -f

SRCS = pushswap.c ./moves/sa.c ./moves/pa.c ./moves/rra.c ./moves/ra.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) push_swap.h
	cc $(CFLAGS) $(SRCS)
	cc $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean
