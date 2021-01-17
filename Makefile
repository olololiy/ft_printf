# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurr <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 13:20:52 by vfurr             #+#    #+#              #
#    Updated: 2021/01/17 13:21:09 by vfurr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprinf.a

HEADER = /lib_ft_printf.h

SRS = ft_printf.c

OBJ = $(SRC:.c)

.c.o:
 $(CC) $(FLAGS) -c $< -o $(<:.c=o)

CC = gcc

AR = ar rc

RM = RM -fr

MAKE = make

LIBFT = ./libft

compile_lib:
           gcc -c ./libft/

$(NAME): compile_lib $(OBJ)
        ar rc $(NAME) $(OBJ) ./libft/*.o
        ranlib $(NAME)


all: $(NAME)

out: $(NAME)
  $(CC) -g $(FLAGS) main.c $(NAME)
  ./a.out

clean:
  $(RM) $(OBJ)
  $(MAKE) clean -C $(LIBFT)

fclean: clean
  $(RM) $(NAME)
  $(MAKE) fclean -C $(LIBFT)

re:  fclean all

.PHONY:  all out clean fclean re