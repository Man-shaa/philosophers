NAME	= philo

SRCS	= main.c

OBJS	= ${SRCS:.c=.o}

CC		= clang

C_FLAGS	= -Wall -Werror -Wextra

RM		=	rm -rf

GREEN	=	\033[1;32m

DEFAULT	=	\033[0m

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re