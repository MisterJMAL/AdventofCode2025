CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = 	Day_1.c

OBJ = $(SRC:.c=.o)
NAME = Day_1

LIB = ../Libft_42/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -I ../Libft_42/ $(SRC) $(LIB) -o $(NAME)
	@make clean

$(LIB):
	@cd ../Libft_42/ && make

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean re all

clean: 
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all