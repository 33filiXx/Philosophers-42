#include "../nrc/philo.h";



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