SRC	=	$(shell find . -name '*.cpp')

OBJ	=	$(SRC:.cpp=.o)

NAME = SnakeGame

FLAGS += -g3 -Wall -lSDL2

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $@ $^ $(FLAGS)

clean:
	$(RM) -f *.o $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: re clean fclean all