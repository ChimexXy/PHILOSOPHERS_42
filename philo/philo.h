#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	int				id;
	int				time;
	int				count_meals;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	long long		last_meal;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				opt_arg;
	pthread_mutex_t	*forks;
	long long		start_time;
	int				dead;
	pthread_mutex_t	print;
	pthread_mutex_t	death_check;
	t_philo			*philos;
}	t_data;

// philo
void	select_things(t_data *philo, char **av);

// parsing
int ft_space_num(char c);
int check_int(char *str);
int av_check(int ac, char **av);
int check_argument(int ac, char **av);

// utils
int ft_atoi(char *str);

#endif
