#include "philo.h"

int check_death(t_philo *philo)
{
	long long now;

	now = get_time();
	pthread_mutex_lock(&philo->data->death_check);
	if (now - philo->last_meal >= philo->data->time_die)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d died 💀\n", now - philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_unlock(&philo->data->death_check);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death_check);
	return (0);
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
		think_philo(philo);
		eat_philo(philo);
		sleep_philo(philo);
		if (check_death(philo) == 1)
			return (NULL);
    }
    return (NULL);
}
