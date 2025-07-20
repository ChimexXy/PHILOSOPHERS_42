#include "philo.h"

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	if (!philo->data->death)
		printf("%lld %d %s\n", get_time() - philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_usleep(long long time, t_data *data)
{
	long long	start;

	start = get_time();
	while (!data->death && (get_time() - start < time))
		usleep(500);
}

void	take_forks(t_philo *philo)
{
    // Philosophe pair prend d'abord la fourchette droite
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
    }
    // Philosophe impair prend d'abord la fourchette gauche
    else
    {
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork");
    }
}

void	eat_philo(t_philo *philo)
{
    if (philo->data->death)
        return;

    take_forks(philo);

    print_status(philo, "is eating");
    pthread_mutex_lock(&philo->data->death_check);
    philo->last_meal = get_time();
    pthread_mutex_unlock(&philo->data->death_check);

    ft_usleep(philo->data->time_eat, philo->data);

    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1500);
	while (!philo->data->death)
	{
		eat_philo(philo);
		if (philo->data->opt_arg > 0 && philo->meals_eaten >= philo->data->opt_arg)
			break;
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_sleep, philo->data);
		print_status(philo, "is thinking");
	}
	return (NULL);
}