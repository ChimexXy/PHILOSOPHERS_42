#include "philo.h"

void intializ_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	while(i < data->num_philo)
	{
		pthread_mutex_init(&data->forks, NULL);
		i++;
	}
	i = 0;
	while(i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].data = data;
		

	}
}