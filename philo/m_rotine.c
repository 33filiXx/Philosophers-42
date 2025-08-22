/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_rotine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:27:37 by wel-mjiy          #+#    #+#             */
/*   Updated: 2025/08/21 19:18:01 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_PHILO/nrc/philo.h"

int	finde_death(t_data *data, int i)
{
	long long	current_time;
	long long	time_since_last_meal;
	long long	last_meal;

	current_time = get_time();
	pthread_mutex_lock(&data->meals);
	last_meal = data->philo[i].last_meal;
	pthread_mutex_unlock(&data->meals);
	time_since_last_meal = current_time - last_meal;
	if (time_since_last_meal >= data->time_to_die)
	{
		pthread_mutex_lock(&data->death);
		if (data->is_died == 0)
		{
			data->is_died = 1;
			pthread_mutex_unlock(&data->death);
			print_state(&data->philo[i], DIED);
			return (1);
		}
		pthread_mutex_unlock(&data->death);
	}
	return (0);
}

int	im_finished_eating(t_data *data)
{
	int	i;

	if (data->must_eat == -1)
		return (0);
	i = 0;
	while (i < data->number_of_philosophe)
	{
		pthread_mutex_lock(&data->meals);
		if (data->philo[i].meals_eaten < data->must_eat)
			return (pthread_mutex_unlock(&data->meals), 0);
		pthread_mutex_unlock(&data->meals);
		i++;
	}
	return (1);
}

int	monitor_death_finder(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophe)
	{
		if (finde_death(data, i))
			return (1);
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	while (1)
	{
		if (monitor_death_finder(data))
			return (NULL);
		if (im_finished_eating(data))
		{
			pthread_mutex_lock(&data->meals);
			data->all_ate = 1;
			pthread_mutex_unlock(&data->meals);
			return (NULL);
		}
	}
	return (NULL);
}