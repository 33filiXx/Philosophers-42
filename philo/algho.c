
#include "42_PHILO/nrc/philo.h"

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophe)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->meals);
	pthread_mutex_destroy(&data->turn);
}

void	cleanup(t_data *data)
{
	if (data->fork)
		destroy_mutexes(data);
	if (data->fork)
		free(data->fork);
	if (data->philo)
		free(data->philo);
}
int	create_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophe)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (printf("%s\n", "Mutex initialization failed"), 1);
		i++;
	}
	if (pthread_mutex_init(&data->death, NULL) != 0)
		return (printf("%s\n", "Mutex initialization failed"), 1);
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (printf("%s\n", "Mutex initialization failed"), 1);
	if (pthread_mutex_init(&data->meals, NULL) != 0)
		return (printf("%s\n", "Mutex initialization failed"), 1);
	if (pthread_mutex_init(&data->turn, NULL) != 0)
		return (printf("%s\n", "Mutex initialization failed"), 1);
	return (0);
}

int	odd_dinner(t_data *data, int *i)
{
	while (*i < 3 && *i < data->number_of_philosophe)
	{
		data->philo[*i].last_meal = data->start_time;
		if (pthread_create(&data->philo[*i].thread, NULL, if_odd_rotine,
				&data->philo[*i]) != 0)
			return (printf("%s\n", "creation failed"), 1);
		(*i)++;
	}
	return (0);
}

int	dinner(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	if (data->number_of_philosophe % 2 != 0)
	{
		if (odd_dinner(data, &i))
			return (1);
	}
	while (i < data->number_of_philosophe)
	{
		data->philo[i].last_meal = data->start_time;
		if (pthread_create(&data->philo[i].thread, NULL, if_even_rotine,
				&data->philo[i]) != 0)
			return (printf("%s\n", "creation failed"), 1);
		i++;
	}
	if (pthread_create(&data->moniteur, NULL, monitor_routine, data) != 0)
		return (printf("%s\n", "creation failed"), 1);
	return (0);
}

void	leonardo_da_vinci_dinner(t_data *data)
{
	int	i;

	i = 0;
	pthread_join(data->moniteur, NULL);
	while (i < data->number_of_philosophe)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	cleanup(data);
}
