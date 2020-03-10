# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 11:46:56 by jotrique          #+#    #+#              #
#    Updated: 2020/03/10 10:47:53 by jotrique         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# Makes everything silent
MAKEFLAGS		+=	--silent

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

SRC_NAME		=	exec/echo.c \
					exec/pwd.c \
					cmd/cmd_init.c \
					signal/signal.c \
					shell/child.c \
					shell/input.c \
					shell/input_process.c \
					shell/parent.c \
					shell/return.c

					# add src/*.c - main.c manually

MKDIR_LST		=	{cmd,exec,signal,shell}

SRC_PATH		= 	src

# SRC				=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

INC_PATH		=	includes

INC_NAME		=	minishell.h \
					exec.h \
					cmd.h \
					shell.h \
					styles.h

INC				=	$(addprefix $(INC_PATH)/,$(INC_NAME))

INC_I			=	$(addprefix -I,$(INC_PATH))

#* Obj

# OBJ				=	$(SRC:.c=.o)
OBJ_PATH		=	.objects
OBJ_NAME		:=	${SRC_NAME:.c=.o}
OBJ 			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


##					##
##		COLORS		##
##					##

GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE = \x1b[37m
RESET = \033[0;37m
ORANGE = \033[38;5;214m
PINK = \033[38;5;197m
END = \x1b[0m
ERASE = \033[2K\r

##					##
##		FONTS		##
##					##

END			=	\033[0m
BOLD		=	\033[1m
R_BOLD		=	\033[21m
BLINK		=	\033[5m
R_BLINK		=	\033[25m
UNDERLINE	=	\033[4m
R_UNDERLINE	=	\033[24m

$(OBJ_PATH)/%.o : 	$(SRC_PATH)/%.c $(INC)
					$(CC) $(CFLAGS) -I $(INC_PATH) -o $@ -c $<
					printf "$(ERASE)$(BLUE)> Compilation :$(END) $<\n"

all				:	makedir dep $(NAME)
					rm -f */*.gch

makedir			:
					@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(MKDIR_LST)

$(NAME)			:	$(OBJ) $(INC)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT_PATH)/libft.a $(INC_I) src/main.c

asan			: 	$(OBJ) $(INC)
					$(CC) $(CFLAGS) $(ASAN) $(OBJ) $(LIBFT_PATH)/libft.a $(INC_I) src/main.c
					./a.out

exec			:
					make all
					#@printf "\n"
					./a.out

# make PARAM=input_init ut
ut $(PARAM)		:
					$(CC) $(CFLAGS) $(OBJ) $(INC_I) src/tests/ut_$(PARAM).c libft/libft.a
					./a.out

dep				:
					make -C $(LIBFT_PATH)

norme			:
					norminette  src/*.c src/parsing src/process includes


# %.o				:	%.c $(INC)
# 					$(CC) -c $< -o $@ $(CFLAGS) -I $(INC_PATH)

#* Much needed tidying up

clean			:
					$(RM) $(OBJ)
					$(RM) $(INC_PATH)/*.gch

fclean			:	clean
					$(RM) $(NAME)
					$(RM) -r $(OBJ_PATH)
					@ make -C $(LIBFT_PATH) fclean

re				:	fclean all