# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 16:21:36 by bchaleil          #+#    #+#              #
#    Updated: 2016/05/26 16:59:37 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	minishell
FLAGS			=	-Wall -Werror -Wextra -g
LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft
INCLUDES		=	-I ./includes -I ./libft/includes
SRCS			=	srcs/main.c srcs/router.c srcs/bultins1.c \
					srcs/bultins2.c srcs/errors.c srcs/env_controller.c\
					srcs/env_controller_ex.c\
					srcs/hash_binaries.c srcs/str_utility.c srcs/builtin_env.c\
					srcs/term.c

OBJS			=	$(SRCS:srcs/%.c=obj/%.o)

# Get system and set specific flags accordingly

ARCH	= $(shell uname -m)
OS		= $(shell uname -s)

ifeq ($(OS)_$(ARCH), Linux_x86_64)
	FLAGS += -D LINUX
else ifeq ($(OS), Linux)
	FLAGS += -D LINUX
endif

all: obj $(NAME)

$(LIB):
	@make -C $(LIB_PATH)

$(NAME): $(OBJS) $(LIB)
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
