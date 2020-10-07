.PHONY: all clean fclean re Makefile

NAME = Colleen

SRCS_PATH = ./srcs/

OBJS_PATH = ./objs/

SRCS_FILES = Colleen.s

OBJS = $(addprefix $(OBJS_PATH), $(SRCS_FILES:.s=.o))

ASM_FLAGS = -f elf64

ASM_COMPILER = nasm

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	@clang -Wall -Wextra -Werror -o $(NAME) $(OBJS_PATH)Colleen.o

$(OBJS_PATH):
	@mkdir $(OBJS_PATH)

$(OBJS_PATH)%.o: %.s
	@$(ASM_COMPILER) $(ASM_FLAGS) -o $@ $^

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all