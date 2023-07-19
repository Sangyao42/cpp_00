# Makefile template for C++ projects
NAME := test
CC := c++

SRCS := iostream_test.cpp
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
#HEADS :=
OBJ_DIR := ./obj/

CPPFLAGS := -std=c++98 -Wall -Wextra -Werror

all : $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $^ -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

run :
	$(MAKE) all
	./$(NAME)

.phony: all clean fclean re run
