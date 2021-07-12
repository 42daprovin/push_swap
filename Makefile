NAME	= push_swap

SRCS	= srcs/create_a.c \
		  srcs/push_swap.c \
		  srcs/swap.c \
		  srcs/push.c \
		  srcs/test.c \
		  srcs/utils.c \
		  srcs/rotate.c \
		  srcs/rev_rotate.c \
		  srcs/small_algorithm.c \
		  srcs/radix_sort.c \
		  srcs/merge_sort.c \
		  srcs/parsing.c

OBJS	= ${SRCS:.c=.o}
FALGS	= -Wall -Werror -Wextra

.c.o:
	gcc -Wall -Werror -Wextra -c -I includes $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libft
	gcc -Wall -Werror -Wextra ${OBJS} libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	make clean -C libft
	rm -f ${OBJS}

fclean: clean
	make fclean -C libft
	rm -f ${NAME}

re: fclean all
