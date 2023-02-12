# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okuyamatakahito <okuyamatakahito@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 23:05:34 by okuyamataka       #+#    #+#              #
#    Updated: 2023/02/12 18:21:54 by okuyamataka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

INCLUDE_DIR	= ./includes/
LIBFT_DIR	= ./libft/
SRCS_DIR	= ./srcs/

FILE_NAME	= \
			ft_eval_format.c \
			ft_print_utils_flags.c \
			ft_print_utils_hex.c \
			ft_print_utils_nbr.c \
			ft_print_utils_str.c \
			ft_printf.c

SRCS		= $(addprefix ${SRCS_DIR}, ${FILE_NAME})
OBJS		= $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -I${INCLUDE_DIR} -I$(LIBFT_DIR) $< -o $@

$(NAME):	$(OBJS)
			make -C ./libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)
		
all:	$(NAME)

clean:
		rm -f $(OBJS)
		make fclean -C $(LIBFT_DIR)

fclean:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT_DIR)

re:		fclean all

test:
	make
	$(CC) $(CFLAGS) -I${INCLUDE_DIR} -I$(LIBFT_DIR) $(NAME) $(SRCS_DIR)main.c
	./a.out
	rm -rf ./a.out
	make fclean
