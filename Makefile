# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 11:45:29 by Jroldan-          #+#    #+#              #
#    Updated: 2023/06/14 13:39:52 by Jroldan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAG = -Wall -Werror -Wextra
RM = rm -f
DIR_SRC = ./src/
DIR_LIBFT = ./libft
LIBFT = $(DIR_LIBFT)/libft.a
SRC =	$(DIR_SRC)/main.c $(DIR_SRC)/operation_list.c  $(DIR_SRC)/check_values.c \
		$(DIR_SRC)/push_swap_utils.c $(DIR_SRC)/movements.c
MAKE = make

#INCLUDES =	push_swap.h libft/libft.h

all :	$(LIBFT) $(NAME)
		@echo completed

$(NAME) :	$(OBJ)	
			@$(CC) $(CFLAG) $(SRC) -o $(NAME) $(LIBFT)
			@echo completed
			
OBJ = $(SRC:.c=.o)

# libft:	$(DIR_LIBFT)
$(LIBFT):	$(DIR_LIBFT)
		@$(MAKE) -C $(DIR_LIBFT)
		@echo completed
		
re: fclean all

clean:
	@$(MAKE) -s clean -C $(DIR_LIBFT)
	@$(RM) $(OBJ)

fclean:	clean
		@$(MAKE) -s fclean -C $(DIR_LIBFT)	
		@$(RM) $(NAME)

.PHONY : all libft re clean fclean
