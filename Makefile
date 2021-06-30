NAME	= push_swap

SRCS	= srcs/create_a.c \
		  srcs/push_swap.c \
		  srcs/swap.c \
		  srcs/push.c \
		  srcs/test.c \
		  srcs/utils.c \
		  srcs/rotate.c \
		  srcs/rev_rotate.c \
		  srcs/quick_sort.c

OBJS	= ${SRCS:.c=.o}

.c.o:
	gcc -c -I includes $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libft
	gcc ${OBJS} libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	make clean -C libft
	rm -f ${OBJS}

fclean: clean
	make fclean -C libft
	rm -f ${NAME}

re: fclean all
