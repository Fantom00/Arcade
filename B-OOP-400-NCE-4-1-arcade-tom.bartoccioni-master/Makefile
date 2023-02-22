##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

REDDARK	=	\033[31;1m
RED		=	\033[31;1m
GREEN	=	\033[32;1m
YEL		=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
WHITE	=	\033[0m

NAME =	arcade

SRC	 =	src/main.cpp	\
		src/core/Core.cpp	\

OBJS		=	$(SRC:.cpp=.o)

CFLAGS		=	-g3 -Wall -Wextra -Werror

all:	games graphicals $(OBJS)
	g++ -o $(NAME) $(OBJS) -lncurses -lsfml-graphics -lsfml-window -lsfml-system -ldl
	@printf "\n\n$(YEL)  [MAKE] → $(GREEN)Compile completed.\n\n$(WHITE)"
	@printf "$(YEL)  [MAKE] → $(WHITE)Binaire : $(CYAN)./%s\n\n$(WHITE)" $(NAME)

core:	$(OBJS)
	g++ -o $(NAME) $(OBJS) -lncurses -lsfml-graphics -lsfml-window -lsfml-system -ldl
	@printf "\n\n$(YEL)  [MAKE] → $(GREEN)Compile completed.\n\n$(WHITE)"
	@printf "$(YEL)  [MAKE] → $(WHITE)Binaire : $(CYAN)./%s\n\n$(WHITE)" $(NAME)

graphicals:
	g++ -shared -fPIC -o lib/arcade_sfml.so src/graphique/sfml/GraphiqueSfml.cpp -lsfml-graphics -lsfml-window -lsfml-system
	g++ -shared -fPIC -o lib/arcade_ncurses.so src/graphique/ncurse/GraphiqueNCurse.cpp -lncurses

games:	
	g++ -shared -fPIC -o lib/arcade_nibbler.so src/games/snake/GameSnake.cpp

clean:
	rm -f $(OBJS)
	@printf "\n\n$(YEL)  [MAKE] → $(GREEN)Clean completed.\n\n\n$(WHITE)"

fclean:	clean
	rm -f $(NAME)
	rm -f lib/*
	@printf "\n\n$(YEL)  [MAKE] → $(GREEN)FClean completed.\n\n\n$(WHITE)"

re:	fclean all