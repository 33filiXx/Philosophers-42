
#include "../nrc/philo.h"

size_t	ft_atoi(char *str)
{
	int	(i) , (s);
	size_t r;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * s);
}

int	ft_is_char_degit(char a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

int number_checker(char **av)
{
	int (i) , (j);

    i = 0;
    while (av[i])
    {
		j = 0;
    	while (av[i][j])
    	{
           if (!ft_is_char_degit(av[i][j]))
               return 1;
           j++;
		}
    i++;
    }
    return 0;
}

int check_if_above_m(char **av)
{
	int i = 0;
	while(av[i])
	{
		if (ft_atoi(av[i]) > INT_MAX)
			return 1;
		i++;
	}
	return 0;
}

int store_data(char **av  , t_philo_data *philo_data)
{
	if (check_if_above_m(av))
		return 1;
	philo_data->number_of_philosophe = ft_atoi(av[0]);
	philo_data->time_to_die = ft_atoi(av[1]);
	philo_data->time_to_eat = ft_atoi(av[2]);
	philo_data->time_to_sleep = ft_atoi(av[3]);
	if (av[4])
		philo_data->number_of_times_each_philosopher_must_eat = ft_atoi(av[4]);
	return 0;
}

int parsing_philo_data(char **av  , t_philo_data *philo_data)
{
	if(number_checker(av))
		return 1;
	if(store_data(av , philo_data))
		return 1;
	return 0;
}