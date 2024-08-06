# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 13:38:18 by adiban-i          #+#    #+#              #
#    Updated: 2024/08/06 12:40:05 by adiban-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
BLACK = "\033[0;30m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
MAGENTA = "\033[0;35m"
CYAN = "\033[0;36m"
WHITE = "\033[0;37m"
NC = "\033[0;0m"  # NO COLOR
UP = "\033[A"
CUT = "\033[K"

# RULES
SERVER = server
CLIENT = client
CC = gcc
CC = gcc
CFLAGS = -Wall -Wextra -O2 -g -I$(LIBFT) -I$(PRINTF)#-Werror
LIBFT = libft
PRINTF = ft_printf

all: libft libftprintf
	@echo $(CYAN)Compiling server and client...$(NC)
	@$(CC) $(CFLAGS) server.c -o $(SERVER) -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
	@$(CC) $(CFLAGS) client.c -o $(CLIENT) -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
	@echo $(GREEN)Compilation of server and client is successful 🎉$(NC)
	
libft:
	@echo $(CYAN)Building ft library...$(NC)
	make -s -C libft

libftprintf:
	@echo $(MAGENTA)Building ftprintf library...$(NC)
	make -s -C $(PRINTF)

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	make -C $(PRINTF) clean
	@echo $(RED)Cleaned objects and library objects$(NC)
	
fclean: clean
	rm -f server client libft/libft.a $(PRINTF)/libftprintf.a
	@echo $(RED)Cleaned all objects, libs and programs$(NC)

re: fclean all

.PHONY: all clean fclean re bonus libft libftprintf