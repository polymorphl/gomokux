##
## Makefile for gomoku in /home/rendu/gomokux
## 
## Made by bort benjamin
## Login   <bort_b@epitech.net>
## 

NAME	= gomoku

SRCS	= Graphic.cpp \
	  Gomoku.cpp \
	  Player.cpp \
	  Exception.cpp \
	  AI.cpp \
	  LuaCommunication.cpp \
	  main.cpp

OBJS	= $(SRCS:.cpp=.o)

CXX	= g++ -o

LDFLAGS	= -llua -lSDL -lSDL_image -ldl

CXXFLAGS	= -Wall -Werror -Wextra

RM	= rm -rvf

$(NAME):	$(OBJS)
		$(CXX) $(NAME) $(OBJS) $(LDFLAGS) $(CXXFLAGS)

all:	$(NAME)

clean:
	$(RM) *~
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re:	fclean all
