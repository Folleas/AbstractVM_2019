##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

GPP			=	g++

RM			=	rm -rf

NAME		=	abstractVM

COMPILEFLAG	=	-g

INCLUDE		=	-Iinclude/

CPPFLAGS    =	$(COMPILEFLAG) $(INCLUDE)

SRC			=	src/main.cpp					\
				src/Core/Memory.cpp				\
				src/Core/Factory.cpp			\
				src/Core/CPU.cpp				\
				src/Core/Machine.cpp			\
				src/Miscellaneous/Parser.cpp	\
				src/Miscellaneous/Utils.cpp		\
				src/Operand/AOperand.cpp		\
				src/Operand/BigDecimal.cpp		\
				src/Operand/Double.cpp			\
				src/Operand/Float.cpp			\
				src/Operand/Int8.cpp			\
				src/Operand/Int16.cpp			\
				src/Operand/Int32.cpp

OBJ			=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[01m\033[31mLinking ...\033[00m"
	@$(GPP) $(OBJ) -o $(NAME) $(CPPFLAGS) $(CPPFLAGS)
	@echo -e "\033[01m\033[32mStandard compilation done => ${NAME}\033[00m"

clean:
	@$(RM) src/*.o src/Operand/*.o src/Core/*.o src/Miscellaneous/*.o *.gcda
	@echo -e "\033[01m\033[31mRemoving useless files ...\033[00m"

fclean:	clean
	@$(RM) $(NAME) unit_tests
	@echo -e "\033[01m\033[31mRemoving binary : {${NAME}} ...\033[00m"

re:	fclean
	@make all --no-print-directory

.PHONY:	all clean fclean re
