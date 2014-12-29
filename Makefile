
NAME	=	gomoklax

SRC	=	AI.cpp \
		Gomoku.cpp \
		Graphic.cpp \
		Rules.cpp \
		Exception.cpp \
		main.cpp \
		Player.cpp

OBJ	=	$(SRC:.cpp=.o)

CXX	=	g++ -o

CXXFLAGS	=	-W -Wall -Wextra

LDFLAGS =	-lSDL -lSDL_image

$(NAME)	:	$(OBJ)
		$(CXX) $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

all	:	$(NAME)

clean	:
	        $(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
