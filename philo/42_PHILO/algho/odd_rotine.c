#include "../nrc/philo.h";

void	odd_eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->meals);
    philo->last_meal = get_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->data->meals);
    print_state(philo , EATING);
    custom_sleep(philo->data->time_to_eat , philo);
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

void	*rotine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		exact_take_fork(philo);
		odd_eating(philo);
		sleeping_then_think(philo);
	}
	return (NULL);
}