# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 13:14:53 by gvynogra          #+#    #+#              #
#    Updated: 2019/09/07 13:14:56 by gvynogra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	avm

SRCS = 	Lexer.cpp		\
		Parser.cpp		\
		Factory.cpp     \
		Token.cpp       \
		AVM.cpp			\
		main.cpp	

		

HDRS = 	IOperand.hpp	\
		Operand.hpp		\
		Operand.cpp		\
		Lexer.hpp		\
		Token.cpp       \
		AVM.hpp			\
		Parser.hpp		\
		SuperStack.hpp	\
		SuperStack.cpp	\
		Factory.hpp		\
		defines.h

CC		= clang++
FLAGS	= -Wall -Wextra -Werror -std=c++11

all: 	$(NAME)

$(NAME): $(SRCS) $(HDRS)	 
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	rm $(NAME)

fclean: clean

re: fclean all
