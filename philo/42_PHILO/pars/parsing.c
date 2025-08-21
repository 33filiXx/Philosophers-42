
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


void handle_even(t_data *data , int signle)
{
	int i = 0;
	if (signle == 1)
		i = 3;
	while (i <data->number_of_philosophe - 1)
	{
		data->philo[i].id = i + 1; 
		data->philo[i].left_fork = i; 
		data->philo[i].right_fork = i + 1;
		i++;
		data->philo[i].id = i + 1; 
		data->philo[i].left_fork = i; 
		data->philo[i].right_fork = i - 1;
		i++;
	}
}

void handle_ode_even(t_data *data)
{
	data->philo[0].id = 1;
	data->philo[0].left_fork = 0;
	data->philo[0].right_fork = 1;

	data->philo[1].id = 2;
	data->philo[1].left_fork = 1;
	data->philo[1].right_fork = 2;

	data->philo[2].id = 3;
	data->philo[2].left_fork = 2;
	data->philo[2].right_fork = 0;
	handle_even(data , 1);
}

int store_data(char **av  , t_data *data)
{
	if (check_if_above_m(av))
		return 1;
	data->number_of_philosophe = ft_atoi(av[0]);
	data->time_to_die = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);	
	if (av[4])
		data->must_eat = ft_atoi(av[4]);
	else
		data->must_eat = 0;
	data->current_turn = 0;
	data->is_died = 0;
	data->philo = malloc(sizeof(t_philo) * data->number_of_philosophe);
	if(!data->philo)
	{
		free(data);
		return 1;
	}
	data->fork = malloc(data->number_of_philosophe * sizeof(pthread_mutex_t));
	if(!data->fork)
	{
		free(data->philo);
		free(data);
		return 1;
	}
	if (data->number_of_philosophe  % 2 == 0)
		handle_even(data , 0);
	else
		handle_ode_even(data);
	return 0;
}

int parsing_philo_data(char **av  , t_data *philo_data)
{
	if(number_checker(av))
		return 1;
	if(store_data(av , philo_data))
		return 1;
	return 0;
}