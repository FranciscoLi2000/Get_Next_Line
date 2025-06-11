# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 20:53:18 by yufli             #+#    #+#              #
#    Updated: 2025/06/11 20:57:05 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -rf

GREEN		= \033[0;32m
BLUE		= \033[0;34m
RED		= \033[0;31m
RESET		= \033[0m

SRC_FILES	= get_next_line.c get_next_line_utils.c
OBJ_FILES	= $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(BLUE)🔧 Archiving $(NAME)...$(RESET)"
	$(AR) $(NAME) $(OBJ_FILES)
	@echo "$(GREEN)Build complete!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	$(RM) $(OBJDIR) $(OBJ_FILES)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
