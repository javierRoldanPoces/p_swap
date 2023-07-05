# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javier <javier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 11:45:29 by Jroldan-          #+#    #+#              #
#    Updated: 2023/07/05 17:42:41 by javier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAG = -Wall -Werror -Wextra
RM = rm -fr

DIR_SRC =	./src/
DIR_LIBFT =	./libft
DIR_FT_PRINTF	=	./ft_printf

FT_PRINTF	= $(DIR_FT_PRINTF)/ft_printf.a
LIBFT = $(DIR_LIBFT)/libft.a

SRC =	$(DIR_SRC)/main.c $(DIR_SRC)/operation_list.c  $(DIR_SRC)/check_values.c \
		$(DIR_SRC)/movements_swap.c $(DIR_SRC)/movements_push.c \
		$(DIR_SRC)/movements_rotate.c $(DIR_SRC)/movements_reverse.c $(DIR_SRC)/operation_list2.c \
		$(DIR_SRC)/check_values2.c $(DIR_SRC)/push_swap.c $(DIR_SRC)/push_swap_utils.c $(DIR_SRC)/sort.c \
		$(DIR_SRC)/push_swap_utils2.c

OBJ = $(SRC:.c=.o)

all :	$(LIBFT) $(FT_PRINTF) $(NAME)
		@echo completed

$(NAME) :	$(OBJ)	
			@$(CC) $(CFLAG) -g3 $(SRC) -o $(NAME) $(LIBFT) $(FT_PRINTF)
			@echo completed
			
MAKE :	make

$(FT_PRINTF):
			@$(MAKE) -C $(DIR_FT_PRINTF)
			@echo completed

$(LIBFT):	$(DIR_LIBFT)
			@$(MAKE) -C $(DIR_LIBFT)
			@echo completed
		
re: fclean all

clean:
		@$(MAKE) -s clean -C $(DIR_LIBFT)
		@$(MAKE) -s clean -C $(DIR_FT_PRINTF)
		@$(RM) $(OBJ)
		@echo completed

fclean:	clean
		@$(MAKE) -s fclean -C $(DIR_LIBFT)
		@$(MAKE) -s fclean -C $(DIR_FT_PRINTF)	
		@$(RM) $(NAME)
		@echo completed

.PHONY : all clean fclean re
