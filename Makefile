# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 18:43:14 by ntojamur          #+#    #+#              #
#    Updated: 2022/03/10 21:03:24 by ntojamur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

NAME	=	compile

LIBFT	=	libft/libft.a

SERV	=	server

CLINT	=	client

SERV_B	=	server_bonus

CLINT_B	=	client_bonus

SOURSES_CLIENT		=	client.c
SOURSES_SERVER		=	server.c
SOURSES_CLIENT_B	=	client_bonus.c
SOURSES_SERVER_B	=	server_bonus.c

OBJECTS_CLIENT		=	$(SOURSES_CLIENT:.c=.o)
OBJECTS_SERVER		=	$(SOURSES_SERVER:.c=.o)
OBJECTS_CLIENT_B	=	$(SOURSES_CLIENT_B:.c=.o)
OBJECTS_SERVER_B	=	$(SOURSES_SERVER_B:.c=.o)


all				:	$(NAME)

$(NAME)			:	$(SERV) $(CLINT) $(LIBFT) Makefile

$(SERV)			:	$(OBJECTS_SERVER) $(LIBFT)
					$(CC) $(FLAGS) $(LIBFT) $(OBJECTS_SERVER)  -o $(SERV)

$(CLINT)		:	$(OBJECTS_CLIENT) $(LIBFT)
					$(CC) $(FLAGS) $(LIBFT) $(OBJECTS_CLIENT)  -o $(CLINT)

bonus			:	$(SERV_B) $(CLINT_B) $(LIBFT) Makefile

$(SERV_B)		:	$(OBJECTS_SERVER_B) $(LIBFT)
					$(CC) $(FLAGS) $(LIBFT) $(OBJECTS_SERVER_B) -o $(SERV_B)

$(CLINT_B)		:	$(OBJECTS_CLIENT_B) $(LIBFT)
					$(CC) $(FLAGS) $(LIBFT) $(OBJECTS_CLIENT_B) -o $(CLINT_B)

$(LIBFT)		:	libft/*.c libft/*.h libft/Makefile
					make -C libft

%.o		:	%.c
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			rm -f $(OBJECTS_CLIENT) $(OBJECTS_SERVER) $(OBJECTS_CLIENT_B) $(OBJECTS_SERVER_B)
			make -C libft clean

fclean	:	clean
			rm -f $(SERV) $(CLINT) $(SERV_B) $(CLINT_B) $(LIBFT)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
