# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 13:38:18 by adiban-i          #+#    #+#              #
#    Updated: 2024/08/05 14:23:32 by adiban-i         ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -O2 -g -I$(LIBFT) #-Werror
LIBFT = libft

all: libft
	@echo $(CYAN)Compiling server and client...$(NC)
	@$(CC) $(CFLAGS) server.c -o $(SERVER) -L$(LIBFT) -lft
	@$(CC) $(CFLAGS) client.c -o $(CLIENT) -L$(LIBFT) -lft
	@echo $(GREEN)Compilation of server and client is successful 🎉$(NC)
	
libft:
	@echo $(CYAN)Building libft library...$(NC)
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re