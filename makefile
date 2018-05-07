# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corosteg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 20:01:26 by corosteg          #+#    #+#              #
#    Updated: 2017/03/13 15:53:00 by corosteg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_PATH = ./libft/
LIB = $(LIB_PATH)/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c ft_check_and_stock.c ft_cpy_if_possible.c ft_valid_pcs.c\
		ft_modif.c ft_print.c ft_result.c ft_map_check.c ft_map_gen.c\
		ft_modif4.c ft_yes_is_possible.c ft_check_first_n.c

#COLORS
C_GOOD			=	"\033[32m"

#MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$

all: $(NAME)

$(NAME): 
		make -C ./libft/
		@$(CC) $(FLAGS) $(SRCS) $(LIB) -o $(NAME)
		@echo "Compiling" [ $(NAME) ] $(SUCCESS)
cc:
		@$(CC) $(SRC) $(LIB) -o $(NAME)

clean:
		make -C ./libft/ clean

fclean: clean
		/bin/rm -f $(NAME)
		make -C ./libft/ fclean

re: fclean all
