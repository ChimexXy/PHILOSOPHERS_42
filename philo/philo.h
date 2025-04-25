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

} t_philo;

int ft_atoi(char *str);

#endif