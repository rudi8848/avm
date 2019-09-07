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
		Lexer.hpp		\
		AVM.hpp			\
		Parser.hpp		\
		SuperStack.hpp	\
		Factory.hpp	

		

all: 	$(NAME)

$(NAME): $(SRCS) $(HDRS)	 
	g++ -std=c++11 -Wall -Wextra -Werror -o $(NAME) $(SRCS)

clean:
	rm $(NAME)


re: clean $(NAME)
