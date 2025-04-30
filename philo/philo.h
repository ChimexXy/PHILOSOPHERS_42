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
	int				left_fork;
	int				right_fork;
	int				eat_count;
	int				last_meal_count;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				opt_arg;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print;

	t_philo			*philos;
}	t_data;

// philo
void	select_things(t_data *philo, char **av);
void	init_all(t_data *data);
void	create_threads(t_data *data);
void    join_threads(t_data *data);
void    clean_all(t_data *data);

// parsing
int ft_space_num(char c);
int check_int(char *str);
int av_check(int ac, char **av);
int check_argument(int ac, char **av);

// utils
int ft_atoi(char *str);

#endif
