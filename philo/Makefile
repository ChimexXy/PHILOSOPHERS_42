NAME = philo
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror 
SRC = init_data.c philo.c utils.c monitor.c philo_routine.c simulation.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) philo.h 
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
