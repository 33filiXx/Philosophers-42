
#include "../nrc/philo.h";




int create_mutex(t_data *data)
{

	int i;

	i = 0;
	while (i < data->number_of_philosophe)
	{
		if( pthread_mutex_init(&data->fork[i] , NULL) != 0)
			return (printf("%s\n", "Mutex initialization failed"), 1);
		i++;
	}	
	if( pthread_mutex_init(&data->death , NULL) != 0)
		return (printf("%s\n", "Mutex initialization failed"), 1);
	if (pthread_mutex_init(&data->print , NULL) != 0)
		return (printf("%s\n", "Mutex initialization failed"), 1);
	if(pthread_mutex_init(&data->meals , NULL) != 0)
		return (printf("%s\n", "Mutex initialization failed"), 1);
	if(pthread_mutex_init(&data->turn , NULL) != 0)
		return (printf("%s\n", "Mutex initialization failed"), 1);

	return 0;
}


void *rotine(void *args)
{
	t_data *data = (t_data *)args;
	

}


int  diner(t_data *data)
{
	int i;

	i = 0;
	create_mutex(data);
	while (i < data->number_of_philosophe)
	{

	}
	
}





