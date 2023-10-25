NAME = shellium
CC = gcc
CFLAGS = #-Wall -Wextra -Werror 
LIBFT = libft/libft.a
LINKED_LIST = linked_list/liblist.a
RM = rm -f
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(LINKED_LIST) $(NAME)


$(LIBFT):
	make -C libft

$(LINKED_LIST):
	make -C linked_list

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LINKED_LIST) -lreadline -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -I./libft -I./linked_list -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

ffclean: fclean
	make fclean -C linked_list
	make fclean -C libft

re: fclean all

run: all
	./$(NAME)

.PHONY: clean fclean re all



