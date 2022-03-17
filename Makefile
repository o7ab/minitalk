# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 07:04:05 by oabushar          #+#    #+#              #
#    Updated: 2022/03/17 16:20:16 by oabushar         ###   ########.fr        #
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
	$(CC) -o client client.c

${SERVER}:
	$(CC) -o server server.c

${CLIENT_BONUS}:
	$(CC) -o client client_bonus.c

${SERVER_BONUS}:
	$(CC) -o server server_bonus.c

bonus : ${CLIENT_BONUS} ${SERVER_BONUS}
clean :
	rm -rf ${OBJ_NAME} ${BNS_NAME} ${CLIENT} ${SERVER}
fclean: clean
	rm -f ${NAME} 
re: fclean all