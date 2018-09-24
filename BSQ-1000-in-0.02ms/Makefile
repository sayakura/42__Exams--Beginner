# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpeng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/05 21:58:24 by kpeng             #+#    #+#              #
#    Updated: 2018/09/09 22:12:57 by kpeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = srcs/*.c

INCLUDES = includes

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -O3 -o $(NAME) $(SRC)
clean:
	/bin/rm -f
fclean:
	/bin/rm -f $(NAME)
re: fclean all
