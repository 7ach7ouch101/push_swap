NAME = push_swap

CHECKER = checker

CFLAGS = -Wall -Wextra -Werror -c -g

RM = rm -f

SRCS = push_swap.c sa.c pa.c rra.c ra.c sb.c pb.c rrb.c rb.c algo.c algo2.c parsing.c parsing2.c\
		tools.c tools2.c tools3.c p_error.c

C_SRCS = checker.c parsing.c parsing2.c sa.c sb.c ra.c rb.c rra.c rrb.c pa.c pb.c tools.c tools2.c tools3.c

OBJS = $(SRCS:.c=.o)

C_OBJS = $(C_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) push_swap.h
	cc $(CFLAGS) $(SRCS)
	cc $(OBJS) -o $(NAME)

$(CHECKER): $(C_OBJS) push_swap.h
	cc $(CFLAGS) $(C_SRCS)
	cc $(C_OBJS) -o $(CHECKER)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean
