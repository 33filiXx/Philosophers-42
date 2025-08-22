#include "42_PHILO/nrc/philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	custom_sleep(int time_ms, t_philo *philo)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < time_ms)
	{
		if (check_death(philo))
			break ;
		usleep(50);
	}
}

int	philo_should_exit(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meals);
	if (philo->data->all_ate || philo->data->number_of_philosophe == 1)
		return (pthread_mutex_unlock(&philo->data->meals), 1);
	return (pthread_mutex_unlock(&philo->data->meals), 0);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->is_died)
	{
		pthread_mutex_unlock(&philo->data->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death);
	return (0);
}