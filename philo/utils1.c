#include "philo.h"

int ft_atoi(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if(str[i] == '+')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res);
}

void	ft_usleep(long long time_in_ms)
{
	long long start;

	start = get_time();
	while ((get_time() - start) < time_in_ms)
		usleep(500); // bach ma y3ti9 lb CPU bzaf
}

