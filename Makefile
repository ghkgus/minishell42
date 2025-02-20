# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwasong <hwasong@student.42gyeongsan.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 13:35:35 by hwasong           #+#    #+#              #
#    Updated: 2025/02/17 13:38:15 by hwasong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

NAME = minishell

SRCS = minishell.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME) -lreadline -L/opt/homebrew/opt/readline/lib

export LDFLAGS="-L/opt/homebrew/opt/readline/lib"

clean : rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
