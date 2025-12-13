CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = 	Day_2.c

OBJ = $(SRC:.c=.o)
NAME = Day_2

LIB = ../Libft_42/libft.a
LIB_PATH = ../Libft_42/

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -I $(LIB_PATH) $(SRC) $(LIB) -o $(NAME)
	@make clean

$(LIB):
	@cd $(LIB_PATH) && make && make clean

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean re all

clean: 
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all