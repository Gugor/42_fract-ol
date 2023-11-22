# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 17:43:46 by hmontoya          #+#    #+#              #
#    Updated: 2023/07/22 17:12:44 by hmontoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ../../includes
DEPS = ../includes/ft_printf.h Makefile 
OBJ = ft_printf.o ft_set_c.o ft_set_s.o ft_set_d.o ft_set_i.o ft_set_u.o ft_set_u.o ft_set_x.o ft_set_xx.o \
	  ft_set_p.o ft_set_per.o ft_strchr.o ft_strlen.o ft_itoa.o ft_strdup.o ft_calloc.o ft_bzero.o
all: $(NAME)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	@ar rcsv $(NAME) $(OBJ) 

clean :
	@rm -vf $(OBJ)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY : clean fclean re all
