# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 11:19:23 by adiban-i          #+#    #+#              #
#    Updated: 2023/12/16 11:19:23 by adiban-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putnbr_int.c ft_putnbr_uns.c ft_write_hexa.c ft_putstr.c ft_write_ptr.c

OBJS = $(SRCS:.c=.o)

INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

