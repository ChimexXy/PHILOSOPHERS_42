#include "philo.h"

void	select_things(t_philo *philo, char **av)
{
	philo->num_philo = ft_atoi(av[1]);
	philo->time_die = ft_atoi(av[2]);
	philo->time_eat = ft_atoi(av[3]);
	philo->time_sleep = ft_atoi(av[4]);
	philo->opt_arg = -1;
	if(av[5])
		philo->opt_arg = ft_atoi(av[5]);
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
	t_philo *philo;

	if (check_argument(ac, av))
	{
		printf("Invalid Arguments\n");
		exit (1);
	}
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	select_things(philo, av);
	
}