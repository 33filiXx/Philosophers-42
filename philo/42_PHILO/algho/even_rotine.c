/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_rotine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 04:08:15 by wel-mjiy          #+#    #+#             */
/*   Updated: 2025/08/21 06:57:30 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../nrc/philo.h";

void	sleeping_then_think(t_philo *philo)
{
    print_state(philo , SLEEPING);
    custom_sleep(philo->data->time_to_sleep , philo);
    print_state(philo , THINKING);
}
void	puts_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork);
		pthread_mutex_lock(&philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork);
		pthread_mutex_lock(&philo->left_fork);
	}
}
void	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork);
		print_state(philo, TOOK_FORK);
		pthread_mutex_lock(&philo->right_fork);
		print_state(philo, TOOK_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork);
		print_state(philo, TOOK_FORK);
		pthread_mutex_lock(&philo->left_fork);
		print_state(philo, TOOK_FORK);
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meals);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meals);
	print_state(philo, EATING);
	custom_sleep(philo->data->time_to_eat, philo);
    puts_fork(philo);
}

void	*rotine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		take_fork(philo);
		eating(philo);
		sleeping_then_think(philo);
	}
    return NULL;
}
