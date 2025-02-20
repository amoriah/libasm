NAME			=	libasm
LIB				=   $(NAME).a
SRC_DIR 		= 	src
OBJ_DIR 		= 	obj
SRC				=	main.c
OBJ				=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC)) $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(ASM_SRC))
ASM_SRC			=	$(wildcard $(SRC_DIR)/*.s)
GCC				=	gcc
ASM				= 	nasm
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address
AFLAGS			=	-f elf64
LFLAGS			=	-L. -lasm
VGD				= 	valgrind -s --leak-check=full
RM				=	rm -rf
GREEN			=	"\033[1;32m"
EOC				=	"\033[0m"

$(NAME)			:	$(LIB)
					$(GCC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB) $(LFLAGS)
					@echo $(GREEN)SUCCESS$(EOC)

$(LIB)			: 	$(OBJ)
					ar rcs $(LIB) $(OBJ)

$(OBJ_DIR)/%.o 	:	%.c
					mkdir -p $(OBJ_DIR)
					$(GCC) $(CFLAGS) $(LFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o 	:	$(SRC_DIR)/%.s
					$(ASM) $(AFLAGS) -o $@ $<

all				:	$(NAME)

run				:
					./$(NAME)

valgrind		:	all
					$(VGD) ./$(NAME)

clean			:
					$(RM) $(OBJ_DIR)

fclean			:	clean
					$(RM) $(LIB) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re run
