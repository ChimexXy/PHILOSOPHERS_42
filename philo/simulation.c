#include "philo.h"

int	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine, &data->philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&data->monitor, NULL, &monitor_routine, data))
		return (1);
	return (0);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(data->monitor, NULL);
}