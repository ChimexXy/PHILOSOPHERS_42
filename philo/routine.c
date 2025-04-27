#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	// small offset to avoid deadlock in start
	if (philo->id % 2 == 0)
		usleep(1000);

	while (!simulation_stopped(philo->data))
	{
		print_state(philo, "is thinking");

		take_forks(philo);

		pthread_mutex_lock(&philo->data->meal_mutex);
		philo->last_meal = get_time();
		philo->meals++;
		pthread_mutex_unlock(&philo->data->meal_mutex);

		print_state(philo, "is eating");
		ft_usleep(philo->data->time_eat);

		drop_forks(philo);

		print_state(philo, "is sleeping");
		ft_usleep(philo->data->time_sleep);
	}
	return (NULL);
}
