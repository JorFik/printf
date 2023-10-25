# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 21:57:25 by JFikents          #+#    #+#              #
#    Updated: 2023/10/25 16:22:04 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
CC = cc
CALLMAKE = make -C libft/
CCFLAGS = -Wall -Wextra -Werror 
# ADD = -fsanitize=address
OBJ = $(C_FILES:.c=.o)
# OBJ+ = $(C_FILES:.c=.o) $(BONUS_FILES:.c=.o)

NAME = libftprintf.a
H_FILE = ft_printf.h libft/libft.a libft/libft.h

C_FILES = ft_printf.c ft_printf_formato.c ft_select_case.c

# BONUS_FILES =


.PHONY: clean fclean re all

all: $(NAME)

$(NAME) : $(OBJ) $(H_FILE) 
	@$(LIB) $(NAME) $^
libft/libft.a :
	@$(CALLMAKE)

%.o : %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ) $(OBJ+)
	@$(CALLMAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@$(CALLMAKE) fclean

re: fclean all

# bonus: $(OBJ+) $(OBJ) $(H_FILE)
# 	@$(LIB) $(NAME) $^
# %: %.c 
# 	@$(CC) $(CCFLAGS) $(ADD) $(H_FILE) $(C_FILES)

# c: a.out
# 	@$(RM) $^
	