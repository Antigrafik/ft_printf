# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 10:52:39 by mmurgia-          #+#    #+#              #
#    Updated: 2022/06/07 11:30:26 by mmurgia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_print_func.c ft_print_unsigned.c ft_print_hex.c\

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

all: $(NAME)

$(OBJECTS):	%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJECTS)
			$(AR) $@ $^

clean:
			@$(RM) $(OBJECTS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re