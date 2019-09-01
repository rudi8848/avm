NAME =	avm

SRCS = 	IOperand.cpp	\
		Lexer.cpp		\
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
		SuperStack.hpp		\
		Factory.hpp	

		

all: 	$(NAME)

$(NAME): $(SRCS) $(HDRS)	 
	g++ -std=c++11 -Wall -Wextra -Werror -o $(NAME) $(SRCS)

clean:
	rm $(NAME)


re: clean $(NAME)