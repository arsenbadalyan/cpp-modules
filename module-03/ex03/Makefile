# Variables
NAME = nowItsWeird!
COMPILER = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# Source Files
SRC = $(wildcard *.cpp)
LIBS = $(wildcard *.hpp)

# Object Files
OBJ = $(patsubst %.cpp, %.o, $(SRC))

# Rules
all: $(NAME)

$(NAME): $(OBJ) Makefile $(LIBS)
	$(COMPILER) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\nExecutable is - $(NAME)"

ifdef MSG
%.o: %.cpp $(LIBS)
	$(COMPILER) $(CFLAGS) -c $< -o $@ -D SHOW_DEFAULT_MSG=$(MSG)
else
%.o: %.cpp $(LIBS)
	$(COMPILER) $(CFLAGS) -c $< -o $@
endif

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re