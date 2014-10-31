##
## Makefile for nibbler in /home/nadali_t/local/tek2/c++/cpp_nibbler
## 
## Made by nadalie thomas
## Login   <nadali_t@epitech.net>
## 
## Started on  Fri Apr  4 14:08:24 2014 nadalie thomas
## Last update Sun Apr  6 20:49:13 2014 nadalie thomas
##

NAME	= gomoku

SRCS	= Graphic.cpp \
	  Gomoku.cpp \
	  Player.cpp \
	  Exception.cpp \
	  main.cpp

OBJS	= $(SRCS:.cpp=.o)

CXX	= g++ -o

LDFLAGS	= -lSDL -lSDL_image -ldl

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
