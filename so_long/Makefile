# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 16:41:34 by iouardi           #+#    #+#              #
#    Updated: 2022/03/07 17:04:26 by iouardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=            so_long
TEST_FILE=        Test.c
FLAGS=            -Wall -Werror -Wextra
CC=                cc
LIBFT_FILES = libft/ft_isalnum.c \
			libft/ft_isdigit.c \
			libft/ft_memmove.c \
			libft/ft_atoi.c \
			libft/ft_isalpha.c \
			libft/ft_isprint.c \
			libft/ft_memset.c \
			libft/ft_strncmp.c \
			libft/ft_bzero.c \
			libft/ft_isascii.c \
			libft/ft_strlcpy.c \
			libft/ft_strnstr.c \
			libft/ft_strrchr.c \
			libft/ft_memcmp.c \
			libft/ft_toupper.c \
			libft/ft_tolower.c \
			libft/ft_calloc.c \
			libft/ft_strdup.c \
			libft/ft_memchr.c \
			libft/ft_strtrim.c \
			libft/ft_itoa.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_substr.c \
			libft/ft_strmapi.c \
			libft/ft_split.c \
			libft/ft_striteri.c \

SRC_FILES_BONUS = libft/ft_lstnew_bonus.c \
				libft/ft_lstadd_front_bonus.c \
				libft/ft_lstlast_bonus.c \
				libft/ft_lstadd_back_bonus.c \
				libft/ft_lstlast_bonus.c \
				libft/ft_lstsize_bonus.c \
				libft/ft_lstdelone_bonus.c \
				libft/ft_lstclear_bonus.c \
				libft/ft_lstiter_bonus.c
SRC_FILES = so_long.c \
			draw_map.c \
			read_the_map.c \
			parsing_map.c
GNL_FILES = gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ_FILES=			$(SRC_FILES:.c=.o)
OBJ_FILES_BONUS=	$(SRC_FILES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C libft
	@cp libft/libft.a ./
	$(CC) $(OBJ_FILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a $(GNL_FILES) -fsanitize=address -g

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

Bonus:  $(OBJ_FILES_BONUS)
	ar rcs $(NAME) $(OBJ_FILES_BONUS) 

