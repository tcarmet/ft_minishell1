#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/16 17:42:06 by tcarmet           #+#    #+#              #
#    Updated: 2015/02/16 18:24:37 by tcarmet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_sh1

SRC = srcs/ft_sh.c

SRC1 = ft_sh.o

LIBFT = ./libft_v2/

LIBFT_A = ./libft_v2/libft.a

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
			@echo "compiling $(NAME)..."
			@Make -C $(LIBFT) re
			@gcc -c $(FLAG) $(SRC)
			@gcc $(FLAG) $(LIBFT_A) -o $(NAME) $(SRC1)
			@echo "$(NAME) has been created !"
clean : 
			@Make -C $(LIBFT) clean
			@rm -rf $(SRC1)
			@echo "objects files has been removed !"

fclean :	clean
			@Make -C $(LIBFT) fclean
			@rm -rf $(NAME)
			@echo "$(NAME) has been removed !"
git :
			@git add .
			@git commit -m " auto commit "
			@git push
			@echo "PUSHED MOTHA FUCKAAA ! " 

re		: fclean all