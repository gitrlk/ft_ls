# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/14 11:08:40 by jecarol           #+#    #+#              #
#    Updated: 2017/04/17 19:53:50 by jecarol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS += -Wall -Wextra -Werror -g

SRC = srcs/ls_core.c \
		srcs/sort_parser.c\
		srcs/sort.c\
		srcs/args.c\
		srcs/getdata.c\
		srcs/workondir.c\
		srcs/preparedir.c\
		srcs/print.c\
		srcs/print_misc.c\
		srcs/print_l.c\
		srcs/fill_info.c\
		srcs/files_treatment.c\
		srcs/print_more.c\
		srcs/error.c\
		srcs/main.c\

LIB = ./libft/libft.a
CC = @cc
OBJ = $(SRC:.c=.o)

# COLOR
C_GOOD = "\033[32m"
C_DURING = "\033[36m"

# MESSAGE
SUCCESS = $(C_GOOD)COMPILATION SUCCEEDED

all: $(NAME)

$(NAME): $(OBJ)
	@make re -C libft/
	@echo $(C_DURING)"Compiling" [ $(NAME) . . . ]
	$(CC) $(OBJ) $(LIB) -o $(NAME)
	@echo $(SUCCESS)

cc:
		$(CC) -g $(OBJ) $(LIB) -o $(NAME)

clean:
		@/bin/rm -f $(OBJ)
		@make clean -C libft/
		@echo $(C_GOOD)".o FILES DELETED"

fclean: clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft/
		@echo $(C_GOOD)"EXECUTABLE FILE DELETED"

re: fclean all
