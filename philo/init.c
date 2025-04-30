/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:21:07 by mozahnou          #+#    #+#             */
/*   Updated: 2025/04/29 15:18:30 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_all(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	while(i < data->num_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
	i = 0;
	while(i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].last_meal_count = 0;
		data->philos[i].right_fork = i;
		data->philos[i].left_fork = i + 1;
		
	}
}

void *philo_routine(t_philo *philo)
{
	while(1)
	{
		printf("Philosopher %d is thinking\n", philo->id);

        // Taking left fork
        pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
        printf("Philosopher %d has taken left fork\n", philo->id);

        // Taking right fork
        pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
        printf("Philosopher %d has taken right fork\n", philo->id);

        // Eating
        printf("Philosopher %d is eating\n", philo->id);
        usleep(philo->data->time_eat * 1000); // Eating time

        // Dropping right fork
        pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
        // Dropping left fork
        pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);

        // Sleeping
        printf("Philosopher %d is sleeping\n", philo->id);
        usleep(philo->data->time_sleep * 1000); // Sleeping time
	}
}

void create_threads(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->num_philo)
	{
		pthread_create(&data->philos[i].thread, NULL, philo_routine, &data->philos[i]);
		i++;
	}
}

void join_threads(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->num_philo)
	{
		pthread_join(&data->philos[i].thread, NULL);
		i++;
	}
}

void clean_all(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->num_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	free(data->forks);
	free(data->philos);
}