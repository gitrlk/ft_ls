# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecarol <jecarol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 12:20:17 by jecarol           #+#    #+#              #
#    Updated: 2017/04/11 20:24:17 by jecarol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS += -Wall -Wextra -Werror -g

SRC = 	ft_atoi.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_freejoin.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_strsplit.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_printstrs.c \
	ft_lstaddend.c \
	ft_lstforeach.c \

CC = @cc

OBJ = $(SRC:.c=.o)

# COLOR
C_GOOD = "\033[32m"
C_DURING = "\033[36m"

# MESSAGE
SUCCESS = $(C_GOOD)COMPILATION SUCCEEDED

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(C_DURING)"Compiling" [ $(NAME) . . . ]
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(SUCCESS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
