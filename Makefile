#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/16 17:42:06 by tcarmet           #+#    #+#              #
#    Updated: 2015/03/10 19:10:41 by tcoppin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 		= ft_minishell1

DEBUG 		= no
ifeq ($(DEBUG),no)
    FLAGS	=-Wall -Werror -Wextra
else
    FLAGS	=-g
endif
SRC 		= ft_sh.c ft_sh_env.c ft_sh_parse.c ft_sh_built_env.c ft_sh_init.c \
			ft_sh_builtin.c ft_sh_misc.c ft_sh_binary.c
OBJ 		= $(SRC:.c=.o)
INC 		= ft_sh.h
LIBFLAGS 	= -L./libft/ -lft
SRCDIR  	= ./srcs/
OBJDIR  	= ./
INCDIRLIB	= ./libft/includes/
INCDIR		= ./includes/
SRCS    	= $(addprefix $(SRCDIR), $(SRC))
OBJS    	= $(addprefix $(OBJDIR), $(OBJ))
INCS 		= $(addprefix $(INCDIR), $(INC))

.SILENT:

all : 		$(NAME)

$(NAME) :	$(INCS)
ifeq ($(DEBUG),yes)
		echo "\\033[1;31mDEBUG COMPILATION.. (no flags except -g)\\033[0;39m"
else
		echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
endif
		echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
			gcc $(FLAGS) -c $(SRCS) -I$(INCDIR) $(LIBFLAGS) -I$(INCDIRLIB)
			echo "compiling $(NAME)..."
			Make -C libft/
			gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)
			echo "$(NAME) has been created !"

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
			git add .
			echo "Enter Your Commit : "
			read root_path ; git commit -m "$$root_path"
			git push
