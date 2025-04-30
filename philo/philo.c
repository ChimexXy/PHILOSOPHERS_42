#include "philo.h"

void	select_things(t_data *data, char **av)
{
	data->num_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->opt_arg = -1;
	if(av[5])
		data->opt_arg = ft_atoi(av[5]);
}

int ft_space_num(char c)
{
	if (c == 32 || (c >= 9 && c <= 13) 
		|| c == '+' || (c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int check_int(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(ft_space_num(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int av_check(int ac, char **av)
{
	int	i;

	i = 1;
	while(i < ac)
	{
		if (check_int(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int check_argument(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	if (av_check(ac, av))
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

int main(int ac, char **av)
{
	t_data *data;

	if (check_argument(ac, av))
	{
		printf("Invalid Arguments\n");
		exit (1);
	}
	data = malloc(sizeof(t_data) * ft_atoi(av[1]));
	select_things(data, av);
	init_all(data);
    create_threads(data);
    join_threads(data);
    clean_all(data);
    free(data);
}