#include "../nrc/philo.h"

void	get_error(void)
{
	write(2, ">>>>> number of Arguments are not correct <<<<<\n", 49);
	write(2, "u should set just\n[number_of_philosophe]\n", 42);
	write(2, "[time_to_die]\n[time_to_sleep]\n[number_of_times_each", 52);
	write(2, "_philosopher_must_eat] >>> [opsioneel]\n", 40);
}
// void get_error_philo()
// {
//     write(2,">>>>> error <<<<<\n", 19);
// }

// void print_data_and_philos(t_data *data)
// {
//     int i;

//     if (!data)
//     {
//         printf("t_data is NULL\n");
//         return ;
//     }

//     printf("=========== Simulation Data ===========\n");
//     printf("Number of philosophers   : %d\n", data->number_of_philosophe);
//     printf("Time to die (ms)         : %d\n", data->time_to_die);
//     printf("Time to eat (ms)         : %d\n", data->time_to_eat);
//     printf("Time to sleep (ms)       : %d\n", data->time_to_sleep);
//     printf("Must eat (if >0)         : %d\n", data->must_eat);
//     printf("Start time               : %d\n", data->start_time);
//     printf("---------------------------------------\n");

//     // print forks (just show addresses of mutexes)
//     printf("Forks (mutex addresses):\n");
//     for (i = 0; i < data->number_of_philosophe; i++)
//         printf("  Fork[%d] = %p\n", i, (void *)&data->fork[i]);

//     printf("---------------------------------------\n");

//     // print philosopher array
//     printf("Philosophers:\n");
//     for (i = 0; i < data->number_of_philosophe; i++)
//     {
//         t_philo *p = &data->philo[i];
//         printf("Philo %d: left=%d right=%d meals=%d last_meal=%ld\n",
//             p->id, p->left_fork, p->right_fork,
//             p->meals_eaten, p->last_meal);
//     }
//     printf("=======================================\n");
// }

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
	return (0);
}
