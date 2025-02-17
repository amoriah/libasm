NAME	=	libasm
LIB		=   libasm.a
SRC		=	main.c
ASM_SRC	=	ft_strlen.s ft_strcpy.s	ft_strcmp.s ft_strdup.s
OBJ		=	$(SRC:.c=.o) $(ASM_SRC:.s=.o)
RM		=	rm -f
GCC		=	gcc
ASM		= 	nasm
CFLAGS	=	-Wall -Wextra -Werror
AFLAGS	=	-f elf64
LFLAGS	=	-L. -lasm
GREEN	=	"\033[1;32m"
EOC		=	"\033[0m"

$(NAME)	:	$(LIB)
			$(GCC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB) $(LFLAGS)
			@echo $(GREEN)SUCCESS$(EOC)

$(LIB)	: 	$(OBJ)
			ar rcs $(LIB) $(OBJ)

%.o 	:	%.c
			$(GCC) $(CFLAGS) $(LFLAGS) -c $< -o $@

%.o 	:	%.s
			$(ASM) $(AFLAGS) -o $@ $<

all		:	$(NAME)

run		: 	
			./$(NAME)
clean	:		
			$(RM) $(OBJ)
fclean	:	clean
			$(RM) $(LIB) $(NAME)
re		:	fclean all