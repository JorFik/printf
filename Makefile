# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 21:57:25 by JFikents          #+#    #+#              #
#    Updated: 2023/11/20 22:36:23 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -rf
CC = cc
CALLMAKE = make -C $(LIBFT_D)
CFLAGS = -Wall -Wextra -Werror -Ilibft
ADD = -fsanitize=address -g
OBJ+ = $(C_FILES:.c=.o) $(BONUS_FILES:.c=.o)
LIBFT_D = libft/
DEBUGGER = debugger/

NAME = libftprintf.a
H_FILE = ft_printf.h libft/libft.h
A_FILE = $(LIBFT_D)libft.a
C_FILES = ft_printf.c ft_cases.c ft_hex_cases.c ft_cases_bonus.c

.PHONY: clean fclean re all

all: $(NAME)

# bonus: all

$(NAME) : $(A_FILE) $(OBJ+)
	@cp $(A_FILE) $(NAME)
	@$(LIB) $(NAME) $(OBJ+)


$(A_FILE) :
	@$(CALLMAKE)

%.o : %.c 
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ+)
	@$(CALLMAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@$(CALLMAKE) fclean

re: fclean all

%: c $(A_FILE) %.c
	@cp $(A_FILE) $(NAME)
	@$(CC) $(ADD) $(CCFLAGS) $(H_FILE) $(C_FILES) $(A_FILE)
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@mv *.gch $(DEBUGGER)
	@make fclean
	@$(RM) $(LIBFT_D)*.gch

c: fclean
	@$(RM) $(DEBUGGER)* 
	@$(RM) $(LIBFT_D)*.gch 
	@$(RM) *.out *.dSYM *.gch 