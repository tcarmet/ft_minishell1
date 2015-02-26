#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/16 17:42:06 by tcarmet           #+#    #+#              #
#    Updated: 2015/02/26 23:23:14 by tcarmet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 		= ft_sh1

DEBUG 		= no
ifeq ($(DEBUG),no)
    FLAGS	=-Wall -Wextra -Werror
else
    FLAGS	=-g
endif
SRC 		= ft_sh.c
OBJ 		= $(SRC:.c=.o)
INC 		= ft_sh.h
LIBFLAGS 	= -L./libft/ -lft
SRCDIR  	= ./srcs/
OBJDIR  	= ./objs/
INCDIR		= ./includes/
SRCS    	= $(addprefix $(SRCDIR), $(SRC))
OBJS    	= $(addprefix $(OBJDIR), $(OBJ))
INCS 		= $(addprefix $(INCDIR), $(INC))

all : 		$(NAME)

$(NAME) :	$(OBJS) $(INCS)
			echo "compiling $(NAME)..."
			Make -C libft/
			gcc $(FLAG) -o $@ $^ $(LIBFLAGS)
			echo "$(NAME) has been created !"

$(OBJS):	$(SRCS)
ifeq ($(DEBUG),yes)
        echo "\\033[1;31mDEBUG COMPILATION.. (no flags except -g)\\033[0;39m"
else
		echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
endif
		echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
			gcc $(FLAG) -c $(SRCS) $(LIBFLAGS)
			mkdir -p $(OBJDIR)
			mv $(OBJ) $(OBJDIR)

.PHONY: 	clean fclean re

clean : 
			Make -C ./libft/ clean
			rm -rf $(OBJS)
			echo "objects files has been removed !"

fclean :	clean
			Make -C ./libft/ fclean
			rm -rf $(NAME)
			echo "$(NAME) has been removed !"

re		: 	fclean all


git :
			@git add .
			@echo "Enter Your Commit : "
			@read root_path ; git commit -m "$$root_path"
			@git push
