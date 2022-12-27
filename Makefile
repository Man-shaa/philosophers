NAME		=	philo

CREATE_DIR	=	create/

ERROR_DIR	=	error/

FREE_DIR	=	free/

UTILS_DIR	=	utils/

SRCS		=	main.c \
				test_print.c \
				${CREATE_DIR}create.c \
				${ERROR_DIR}error.c \
				${FREE_DIR}free.c \
				${UTILS_DIR}utils.c

OBJS		=	${SRCS:.c=.o}

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra -g3

RM			=	rm -rf

GREEN		=	\033[1;32m

DEFAULT		=	\033[0m

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