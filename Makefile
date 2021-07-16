NAME		=	libftprintf.a

LIBFT_DIR	=	./Libft
LIBFT		=	${LIBFT_DIR}/libft.a

SRC_FILES 	=	ft_checkflags.c ft_printf.c ft_treatnumbers.c ft_treattext.c
HEADER_FILE =	

FLAGS 		=	-Wall -Wextra -Werror
CC 			=	gcc

SRCS 		=	$(SRC_FILES)
OBJS 		=	$(SRCS:c=o)

all: $(NAME)

$(NAME): ${LIBFT} ${OBJS}
	${RM} ${NAME}
	cp ${LIBFT} ${NAME}
	${AR} rcs ${NAME} ${OBJS}

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	@gcc $(FLAGS) -I /printf -c $< -o $@
	@echo "$@ created from $<"

clean:
	@rm -f $(OBJS)
	@echo "OBJECTS deleted"

fclean: clean
	make -C ${LIBFT_DIR} fclean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"


re: fclean all

.PHONY = all clean fclean re
