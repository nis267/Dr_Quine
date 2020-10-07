
.PHONY: all clean fclean re Makefile

NAME = Colleen

OBJS_PATH = ./objs/

SRCS_FILES = Colleen.c

OBJS = $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))

FLAGS = -Wall -Wextra -Werror

CC = clang

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS_PATH)Colleen.o

$(OBJS_PATH):
	@mkdir $(OBJS_PATH)

$(OBJS_PATH)%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all