# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 07:04:05 by oabushar          #+#    #+#              #
#    Updated: 2022/02/23 13:07:05 by oabushar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

CLIENT_BONUS = Client_bonus

SERVER_BONUS = Server_bonus

SRC_NAME = client.c server.c
SRC_BONUS = client_bonus.c server_bonus.c

OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: ${SERVER} ${CLIENT}
${CLIENT}:
	$(MAKE) -C libft
	$(CC) -o client client.c ./libft/libft.a

${SERVER}:
	$(MAKE) -C libft
	$(CC) -o server server.c ./libft/libft.a

${CLIENT_BONUS}:
	$(MAKE) -C libft
	$(CC) -o client client_bonus.c ./libft/libft.a

${SERVER_BONUS}:
	$(MAKE) -C libft
	$(CC) -o server server_bonus.c ./libft/libft.a

bonus : ${CLIENT_BONUS} ${SERVER_BONUS}
clean :
	$(MAKE) clean -C ./libft
	rm -rf ${OBJ_NAME} ${BNS_NAME} ${CLIENT} ${SERVER}
fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f ${NAME} 
re: fclean all