NAME =	avm

SRCS = 	IOperand.cpp	\
		Lexer.cpp		\
		Parser.cpp		\
		Factory.cpp		\
		AVM.cpp			\
		main.cpp	
		#Double.cpp 	\
		#Float.cpp		\
		#Int16.cpp		\
		#Int32.cpp		\
		#Int8.cpp		\
		

HDRS = 	IOperand.hpp	\
		Operand.hpp		\
		Lexer.hpp		\
		AVM.hpp			\
		Parser.hpp		\
		SuperStack.hpp		\
		Factory.hpp	
		#Double.hpp		\
		#Float.hpp		\
		#Int16.hpp		\
		#Int32.hpp		\
		#Int8.hpp		\
		

all: 	$(NAME)

$(NAME): $(SRCS) $(HDRS)	 
	g++ -std=c++11 -Wall -Wextra -Werror -o $(NAME) $(SRCS)

clean:
	rm $(NAME)


re: clean $(NAME)