NAME = philo
CFLAGS = -Wall -Wextra -Werror
SRC = init.c philo.c routine.c utils1.c\


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) philo.h 
	$(CC) $(OBJ) -fsanitize=address -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

