# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 10:45:18 by tponnusa          #+#    #+#              #
#    Updated: 2023/03/04 17:52:45 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   push_swap
CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror

SRC         =   push_swap.c ps_operations.c utils.c utils_list.c sorting.c parsing.c\
				sorting_utils.c push_swap_atoi.c sort_radix.c print_instructions.c

OBJ         =   $(SRC:.c=.o)

all         :   $(NAME)

$(NAME)     :   $(OBJ)
				cd libft && make 
				gcc $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME) 

clean       :	
				rm -f $(OBJ)

fclean      :   clean
				make fclean -C ./libft
				rm -f $(NAME)

re          :   fclean all

norm        :   
				norminette $(SRC)

.PHONY		:	all clean fclean re