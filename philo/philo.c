#include "philo.h"


int	is_valid_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	validate_arguments_content(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_valid_argument(av[i]))
			return (1);
		i++;
	}
	return (0);
}

void	select_things(t_data *data, char **av)
{
	data->num_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (av[5])
		data->opt_arg = ft_atoi(av[5]);
	else
		data->opt_arg = -1;
}

// int validate_arguments_content(int ac, char **av)
// {
// 	int	i;

// 	i = 1;
// 	while(i < ac)
// 	{
// 		if (is_valid_argument(av[i]))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int check_argument(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	if (validate_arguments_content(ac, av))
		return (1);
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
		return (1);
	if (ft_atoi(av[2]) < 60)
		return (1);
	if (ft_atoi(av[3]) < 60)
		return (1);
	if (ft_atoi(av[4]) < 60)
		return (1);
	if (ac == 6 && ft_atoi(av[5]) < 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (check_argument(ac, av) || initialize_data(data, av))
		return (1);
	if (start_simulation(data))
		return (1);
	join_threads(data);
	clean_data(data);
	return (0);
}
