NAME			=	libasm
LIB				=   $(NAME).a
SRC_DIR 		= 	src
OBJ_DIR 		= 	obj
TESTS_DIR		=	tests
HEADER			=	$(TESTS_DIR)/tests.h
C_SRC			=	main.c $(wildcard $(TESTS_DIR)/*.c)
ASM_SRC			=	$(wildcard $(SRC_DIR)/*.s)
OBJ				=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(C_SRC))) \
					$(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(ASM_SRC))
GCC				=	gcc
ASM				= 	nasm
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address -I$(TESTS_DIR)
AFLAGS			=	-f elf64
LFLAGS			=	-L. -lasm
VGD				= 	valgrind -s --leak-check=full
RM				=	rm -rf
GREEN			=	"\033[1;32m"
EOC				=	"\033[0m"

all				:	$(NAME)

$(NAME)			:	$(LIB)
					$(GCC) $(CFLAGS) -o $(NAME) $(C_SRC) $(LIB) $(LFLAGS)
					@echo $(GREEN)SUCCESS$(EOC)

$(LIB)			: 	$(OBJ)
					ar rcs $(LIB) $(OBJ)

$(OBJ_DIR)/%.o 	:	%.c $(HEADER)
					mkdir -p $(OBJ_DIR)
					$(GCC) $(CFLAGS) $(LFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o 	:	$(TESTS_DIR)/%.c $(HEADER)
					$(GCC) $(CFLAGS) $(LFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o 	:	$(SRC_DIR)/%.s
					$(ASM) $(AFLAGS) -o $@ $<
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
