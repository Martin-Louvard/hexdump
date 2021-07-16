SRCS =   ft_display.c  ft_hexdump.c utils.c  utils2.c utils3.c ft_display2.c ft_files.c

OBJS = ${SRCS:.c=.o}

NAME = ft_hexdump

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c  $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
