# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 21:57:25 by JFikents          #+#    #+#              #
#    Updated: 2023/10/27 20:09:12 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
CC = cc
CALLMAKE = make -C libft/
CCFLAGS = -Wall -Wextra -Werror -Ilibft
ADD = -fsanitize=address
OBJ = $(C_FILES:.c=.o)
OBJ+ = $(C_FILES:.c=.o) $(BONUS_FILES:.c=.o)

NAME = libftprintf.a
H_FILE = ft_printf.h libft/libft.h
A_FILE = libft/libft.a
C_FILES = ft_printf.c ft_cases.c ft_hex_cases.c

BONUS_FILES =


.PHONY: clean fclean re all

all: $(A_FILE) $(NAME)

$(NAME) : $(OBJ) $(A_FILE) $(H_FILE) 
	@$(LIB) $(NAME) $^

$(A_FILE) :
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

bonus: $(OBJ+) $(OBJ) $(H_FILE)
	@$(LIB) $(NAME) $^
%: %.c 
	@$(CC) $(CCFLAGS) $(H_FILE) $(C_FILES)

c:
	@$(RM) a.out *.gch
	@$(RM) libft/*.gch