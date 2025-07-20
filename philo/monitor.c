#include "philo.h"

int	check_philo_death(t_philo *philo)
{
    long long	time_since_last_meal;

    pthread_mutex_lock(&philo->data->death_check);
    time_since_last_meal = get_time() - philo->last_meal;
    if (time_since_last_meal > philo->data->time_die && !philo->data->death)
    {
        pthread_mutex_lock(&philo->data->print);
        printf("%lld %d died\n", get_time() - philo->data->start_time, philo->id);
        philo->data->death = 1;
        pthread_mutex_unlock(&philo->data->print);
        pthread_mutex_unlock(&philo->data->death_check);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->death_check);
    return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;
	int		all_eat;

	data = (t_data *)arg;
	while (!data->death)
	{
		i = 0;
		all_eat = 1;
		while (i < data->num_philo)
		{
			if (check_philo_death(&data->philos[i]))
				return (NULL);
			if (data->opt_arg > 0 && data->philos[i].meals_eaten < data->opt_arg)
				all_eat = 0;
			i++;
		}
		if (data->opt_arg > 0 && all_eat)
		{
			pthread_mutex_lock(&data->print);
			data->death = 1;
			printf("All philosophers have eaten %d times\n", data->opt_arg);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}