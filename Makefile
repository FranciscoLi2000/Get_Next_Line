NAME = gnl.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC = get_next_line.c get_next_line_utils.c
BONUS = get_next_line_bonus.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)_bonus

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME) $(NAME)_bonus

re: fclean all

.PHONY: all clean fclean re bonus