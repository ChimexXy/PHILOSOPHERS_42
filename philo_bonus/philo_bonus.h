#ifndef PHILO_BONUS
#define PHILO_BONUS

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <semaphore.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	int			id;
	int			meals_eaten;
	long long	last_meal;
	
	pid_t		pid;

	t_data		*data;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				opt_arg;
	long long		start_time;
	int				stop;

	sem_t			*forks;
	sem_t			*print;
	sem_t			*death;

	t_philo			*philos;
}	t_data;



#endif
