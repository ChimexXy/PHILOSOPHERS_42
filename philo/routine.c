#include "philo.h"

void	*death_checker(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->num_philo)
		{
			pthread_mutex_lock(&data->death_check);
			if (get_time() - data->philos[i].last_meal > data->time_die)
			{
				pthread_mutex_lock(&data->print);
				printf("%lld %d died 💀\n", get_time() - data->start_time, data->philos[i].id);
				data->dead = 1;
				pthread_mutex_unlock(&data->print);
				pthread_mutex_unlock(&data->death_check);
				return (NULL);
			}
			pthread_mutex_unlock(&data->death_check);
			i++;
		}
		usleep(500); // avoid CPU overload
	}
	return (NULL);
}


void eat_philo(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
    
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d has taken a fork 🍴\n", get_time() - philo->data->start_time, philo->id);
	printf("%lld %d has taken a fork 🍴\n", get_time() - philo->data->start_time, philo->id);
	printf("%lld %d is eating 🍽️\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
    
	philo->last_meal = get_time();
	ft_usleep(philo->data->time_eat);
    
	philo->count_meals++;
    
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void sleep_philo(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->print);
	printf("%lld %d is sleeping 😴\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
    
	ft_usleep(philo->data->time_sleep);
}

void think_philo(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->print);
	printf("%lld %d is thinking 🤔\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}


void	*philo_routine(void *arg)
{
    t_philo	*philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        usleep(1000); // small delay for even philosophers

    while (1)
    {
        pthread_mutex_lock(&philo->data->death_check);
        if (philo->data->dead)
        {
            pthread_mutex_unlock(&philo->data->death_check);
            break;
        }
        pthread_mutex_unlock(&philo->data->death_check);
        eat_philo(philo);
        sleep_philo(philo);
        think_philo(philo);
    }
    return (NULL);
}
