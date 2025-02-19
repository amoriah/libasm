NAME	=	libasm
LIB		=   libasm.a
SRC		=	main.c
ASM_SRC	=	ft_strlen.s ft_strcpy.s	ft_strcmp.s ft_strdup.s ft_write.s ft_read.s
OBJ		=	$(SRC:.c=$(OBJ_DIR)/%.o) $(ASM_SRC:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)
SRC_DIR	=	src
OBJ_DIR	=	obj
RM		=	rm -f
GCC		=	gcc
ASM		= 	nasm
#CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address
CFLAGS	=	-Wall -Wextra -Werror
AFLAGS	=	-f elf64
VGD		= 	valgrind -s --leak-check=full
LFLAGS	=	-L. -lasm
GREEN	=	"\033[1;32m"
EOC		=	"\033[0m"

$(NAME)	:	$(LIB)
			$(GCC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB) $(LFLAGS)
			@echo $(GREEN)SUCCESS$(EOC)

$(LIB)	: 	$(OBJ)
			ar rcs $(LIB) $(OBJ)

$(OBJ_DIR)/%.o 	:	%.c
			$(GCC) $(CFLAGS) $(LFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o 	:	$(SRC_DIR)/%.s
			$(ASM) $(AFLAGS) -o $@ $<

all		:	$(NAME) 

run		: 	
			./$(NAME)

#valgrind:	all
#			$(VGD) ./$(NAME)

clean	:		
			$(RM) $(OBJ)
fclean	:	clean
			$(RM) $(LIB) $(NAME)
re		:	fclean all