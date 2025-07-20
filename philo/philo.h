#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal;

	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				opt_arg;
	int				death;
	int				all_eat;
	long long		start_time;

	pthread_t 		monitor;

	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	death_check;

	t_philo			*philos;
}	t_data;

// parsing
void	select_things(t_data *philo, char **av);
int ft_space_num(char c);
int is_valid_argument(char *str);
// int validate_arguments_content(int ac, char **av);
int check_argument(int ac, char **av);

//utils

int ft_atoi(char *str);
long long	get_time(void);

//init_data

int	initialize_data(t_data *data, char **av);

void	*monitor_routine(void *arg);
void	*philo_routine(void *arg);
void	join_threads(t_data *data);
int	start_simulation(t_data *data);
void	print_status(t_philo *philo, char *msg);

void	clean_data(t_data *data);
int	init_forks(t_data *data);
int	init_data_philo(t_data *data);

#endif
