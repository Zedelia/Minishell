# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 11:46:56 by jotrique          #+#    #+#              #
#    Updated: 2020/03/03 13:02:02 by jotrique         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# Makes everything silent
#MAKEFLAGS		+=	--silent

.PHONY			:	all clean fclean re

NAME			=	minishell

#* Common tools

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
OPTI_FLAG		=	-O2
NOPTI_FLAG		=	-O3

#* Testing tools

ASAN			=	-fsanitize=address -g3
VALTAG			=	--leak-check=full --show-leak-kinds=all
VALTRACK		=	--track-origins=yes -s
PED				=	-pedantic
PARANO			=	-pedantic -Wformat=2 -Wno-unused-parameter -Wshadow \
					-Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
					-Wredundant-decls -Wnested-externs -Wmissing-include-dirs \
					-Wjump-misses-init -Wlogical-op #GCC exclusives

#* Dependencies

LIBFT_PATH		=	libft

#* Sources

SRC				=	src/parsing/*.c \
					src/processus/*.c \
					src/command/*.c
					# add src/*.c - main.c manually

INC_PATH		=	includes

INC_NAME		=	*.h

INC				=	$(addprefix $(INC_PATH)/,$(INC_NAME))

OBJ				=	$(SRC:.c=.o)

all				:	$(NAME) dep
					clear

$(NAME)			:	$(OBJ) $(INC)
					$(CC) $(CFLAGS) -I $(INC_PATH) $(OBJ) src/main.c -o $(NAME)

dep				:
					make -C $(LIBFT_PATH)

norme			:
					norminette  src/*.c src/parsing src/process includes

%.o				:	%.c $(INC)
					$(CC) -c $< -o $@ $(CFLAGS) -I $(INC_PATH)

#* Much needed tidying up

clean			:
					$(RM) $(OBJ)
					$(RM) $(INC_PATH)/*.gch

fclean			:	clean
					$(RM) $(NAME)
					@ make -C $(LIBFT_PATH) fclean

re				:	fclean all