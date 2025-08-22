
#include "42_PHILO/nrc/philo.h"

static void	print_philo_state(t_philo *philo, int state)
{
	printf("%lld ", get_time() - philo->data->start_time);
	printf("%d ", philo->id);
	if (state == THINKING)
		printf("is thinking\n");
	else if (state == EATING)
		printf("is eating\n");
	else if (state == SLEEPING)
		printf("is sleeping\n");
	else if (state == TOOK_FORK)
		printf("has taken a fork\n");
	else if (state == DIED)
		printf("died\n");
}

void	print_state(t_philo *philo, int state)
{
	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->is_died == 0 || state == DIED)
	{
		pthread_mutex_unlock(&philo->data->death);
		print_philo_state(philo, state);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->death);
	}
	pthread_mutex_unlock(&philo->data->print);
}