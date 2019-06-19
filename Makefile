NAME =	avm

SRCS = 	Double.cpp 		\
		Float.cpp		\
		IOperand.cpp	\
		Int16.cpp		\
		Int32.cpp		\
		Int8.cpp		\
		Lexer.cpp		\
		Parser.cpp		\
		AVM.cpp			\
		main.cpp	

HDRS = 	Double.hpp		\
		Float.hpp		\
		IOperand.hpp	\
		Int16.hpp		\
		Int32.hpp		\
		Int8.hpp		\
		Lexer.hpp		\
		AVM.hpp			\
		Parser.hpp	

all: 	$(NAME)

$(NAME): $(SRCS) $(HDRS)	 
	g++ -std=c++11 -Wall -Wextra -Werror -o $(NAME) $(SRCS)

clean:
	rm *.o

fclean:
	clean
	rm $(NAME)
