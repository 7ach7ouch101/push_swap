NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -c

RM = rm -f

SRCS = push_swap.c sa.c pa.c rra.c ra.c sb.c pb.c rrb.c rb.c\

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
