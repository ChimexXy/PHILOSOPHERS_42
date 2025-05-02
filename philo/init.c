#include "philo.h"

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void init_philosophers(t_data *data)
{
	int i;

	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return ;
	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].count_meals = 0;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philo];
		data->philos[i].last_meal = 0;
		i++;
	}
}

void init_mutexes(t_data *data)
{
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->death_check, NULL);
}

void start_threads(t_data *data)
{
	int i;

	i = 0;
	data->start_time = get_time(); // function li tjib timestamp dial start
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine, &data->philos[i]))
		{
			printf("Failed to create thread %d\n", i);
			return ;
		}
		i++;
	}
}

void join_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

long long get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
