#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

typedef		struct s_philo{
	int				id;
	int				meals;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
	
} t_philo;

typedef 	struct s_data{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				opt_arg;
	int				stop;
	long			start_time;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	stop_mutex;

	t_philo			*philos;
}	t_data;

// philo
void	select_things(t_data *philo, char **av);

// parsing
int ft_space_num(char c);
int check_int(char *str);
int av_check(int ac, char **av);
int check_argument(int ac, char **av);

int ft_atoi(char *str);

#endif