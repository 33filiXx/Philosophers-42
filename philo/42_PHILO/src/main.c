/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:43:54 by wel-mjiy          #+#    #+#             */
/*   Updated: 2025/08/22 15:43:56 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../nrc/philo.h"

void	get_error(void)
{
	write(2, ">>>>> number of Arguments are not correct <<<<<\n", 49);
	write(2, "u should set just\n[number_of_philosophe]\n", 42);
	write(2, "[time_to_die]\n[time_to_sleep]\n[number_of_times_each", 52);
	write(2, "_philosopher_must_eat] >>> [opsioneel]\n", 40);
}

int	main(int ac, char *av[])
{
	t_data	*philo_data;

	philo_data = malloc(sizeof(t_data));
	if (ac == 5 || ac == 6)
	{
		if (parsing_philo_data(av + 1, philo_data))
		{
			write(2, ">>>>> set only Numbers <<<<<\n", 30);
			return (1);
		}
	}
	else
	{
		free(philo_data);
		get_error();
		return (1);
	}
	if (dinner(philo_data))
		return (cleanup(philo_data), 1);
	leonardo_da_vinci_dinner(philo_data);
	free(philo_data);
	return (0);
}
