/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odd_rotine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:52:13 by wel-mjiy          #+#    #+#             */
/*   Updated: 2025/08/22 15:52:43 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_PHILO/nrc/philo.h"

static void	handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->left_fork]);
	print_state(philo, TOOK_FORK);
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
}

void	odd_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meals);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meals);
	print_state(philo, EATING);
	custom_sleep(philo->data->time_to_eat, philo);
	pthread_mutex_lock(&philo->data->turn);
	puts_fork(philo);
	philo->data->current_turn = (philo->id + 1) % 3;
	pthread_mutex_unlock(&philo->data->turn);
}

void	exact_take_fork(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data->turn);
		if (philo->data->current_turn == philo->id - 1)
		{
			pthread_mutex_unlock(&philo->data->turn);
			break ;
		}
		pthread_mutex_unlock(&philo->data->turn);
	}
	take_fork(philo);
}

void	*if_odd_rotine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!(check_death(philo)))
	{
		if (philo->data->number_of_philosophe == 1)
			handle_single_philo(philo);
		if (philo_should_exit(philo))
			break ;
		exact_take_fork(philo);
		odd_eating(philo);
		sleeping_then_think(philo);
	}
	return (NULL);
}
