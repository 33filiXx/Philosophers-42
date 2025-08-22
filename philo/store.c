/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:57:38 by wel-mjiy          #+#    #+#             */
/*   Updated: 2025/08/22 15:57:56 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_PHILO/nrc/philo.h"

void	handle_even(t_data *data, int signle)
{
	int	i;

	i = 0;
	if (signle == 1)
		i = 3;
	while (i < data->number_of_philosophe - 1)
	{
		data->philo[i].id = i + 1;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = i + 1;
		data->philo[i].data = data;
		data->philo[i].meals_eaten = 0;
		data->philo[i].last_meal = 0;
		i++;
		data->philo[i].id = i + 1;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = i - 1;
		data->philo[i].data = data;
		data->philo[i].meals_eaten = 0;
		data->philo[i].last_meal = 0;
		i++;
	}
}

void	initialize_one_philo(t_data *data)
{
	data->philo[0].id = 1;
	data->philo[0].left_fork = 0;
	data->philo[0].data = data;
	data->philo[0].meals_eaten = 0;
}

void	handle_ode_even(t_data *data)
{
	if (data->number_of_philosophe == 1)
	{
		initialize_one_philo(data);
		return ;
	}
	data->philo[0].id = 1;
	data->philo[0].left_fork = 0;
	data->philo[0].right_fork = 1;
	data->philo[0].data = data;
	data->philo[0].meals_eaten = 0;
	data->philo[0].last_meal = 0;
	data->philo[1].id = 2;
	data->philo[1].left_fork = 1;
	data->philo[1].right_fork = 2;
	data->philo[1].data = data;
	data->philo[1].meals_eaten = 0;
	data->philo[1].last_meal = 0;
	data->philo[2].id = 3;
	data->philo[2].left_fork = 2;
	data->philo[2].right_fork = 0;
	data->philo[2].data = data;
	data->philo[2].meals_eaten = 0;
	data->philo[2].last_meal = 0;
	handle_even(data, 1);
}

int	store_data(char **av, t_data *data)
{
	if (check_if_above_m(av))
		return (1);
	data->number_of_philosophe = ft_atoi(av[0]);
	data->time_to_die = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	if (av[4])
		data->must_eat = ft_atoi(av[4]);
	else
		data->must_eat = -1;
	data->current_turn = 0;
	data->is_died = 0;
	data->all_ate = 0;
	data->philo = malloc(sizeof(t_philo) * data->number_of_philosophe);
	if (!data->philo)
		return (free(data), 1);
	data->fork = malloc(data->number_of_philosophe * sizeof(pthread_mutex_t));
	if (!data->fork)
		return (free(data->philo), free(data), 1);
	if (data->number_of_philosophe % 2 == 0)
		handle_even(data, 0);
	else
		handle_ode_even(data);
	return (0);
}

int	parsing_philo_data(char **av, t_data *philo_data)
{
	if (number_checker(av))
		return (cleanup(philo_data), 1);
	if (store_data(av, philo_data))
		return (1);
	if (create_mutex(philo_data))
		return (1);
	return (0);
}
