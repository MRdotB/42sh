# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <bchaleil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 12:49:42 by bchaleil          #+#    #+#              #
#    Updated: 2016/04/27 13:21:57 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
NAME = libft.a
INCLUDES = -I ./includes

# Get system and set specific flags accordingly

ARCH	= $(shell uname -m)
OS		= $(shell uname -s)

ifeq ($(OS)_$(ARCH), Linux_x86_64)
	CFLAGS += -D LINUX
else ifeq ($(OS), Linux)
	CFLAGS += -D LINUX
endif

SRCS = strlen strdup strcpy strncpy strcat strncat strchr strrchr strlcat\
	  strstr strnstr strcmp strtrim strncmp strdel strnew strclr striter \
	  striteri strmap strmapi strequ strnequ strsub strjoin strsplit\
	  strindexof strlastindexof strsplitstr concat\
	  string_new string_free string_enlarge string_append\
	  memalloc memmove memset memcpy memccpy memchr memcmp memdel bzero\
	  atoi itoa\
	  toupper tolower\
	  putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd\
	  putnbr_fd putnbrnl putnbrll print_binary\
	  lstnew lstdelone lstdel lstadd lstiter lstmap lstpush\
	  pow\
	  gnl
SRCS := $(addprefix ft_, $(SRCS))

HASH = create free get hash newpair set
HASH := $(addprefix ht_, $(HASH))

SRCS += $(HASH)

SRCS := $(addsuffix .c, $(SRCS))
OBJS = $(SRCS:%.c=obj/%.o)

all: obj $(NAME)

$(NAME):	$(OBJS)
	@ar rc $@ $^ 
	@ranlib $(NAME)

obj:
	@mkdir -p obj

obj/%.o: string/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

obj/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

obj/%.o: list/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

obj/%.o: mem/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

obj/%.o: print/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

obj/%.o: math/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

obj/%.o: hashtable/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
