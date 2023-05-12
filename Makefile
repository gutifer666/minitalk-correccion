# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 17:41:16 by frgutier          #+#    #+#              #
#    Updated: 2022/12/08 18:12:32 by frgutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

BONUS_SOURCES = server_bonus.c client_bonus.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server_bonus client_bonus

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

server_bonus: server_bonus.o libft
	$(CC) -o server $< -Llibft -lft

client_bonus: client_bonus.o libft
	$(CC) -o client $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client server_bonus client_bonus libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re