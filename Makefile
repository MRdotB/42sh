# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 16:21:36 by bchaleil          #+#    #+#              #
#    Updated: 2016/04/28 19:17:33 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	minishell
FLAGS			=	-Wall -Werror -Wextra
LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft
INCLUDES		=	-I ./includes -I ./libft/includes
SRCS			=	srcs/main.c srcs/router.c srcs/bultins.c
OBJS			=	$(SRCS:srcs/%.c=obj/%.o)

all: obj $(NAME)

$(LIB):
	@make -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJS)
	@cat asciiart
	$(CC) $(FLAGS) -o $@ $^


obj:
	@mkdir -p obj

obj/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all

.PHONY:clean fclean re
