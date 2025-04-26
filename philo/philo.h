#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_philo{
	int num_philo;
	int time_die;
	int time_eat;
	int time_sleep;
	int	opt_arg;

} t_philo;

// philo
void	select_things(t_philo *philo, char **av);

// parsing
int ft_space_num(char c);
int check_int(char *str);
int av_check(int ac, char **av);
int check_argument(int ac, char **av);

int ft_atoi(char *str);

#endif