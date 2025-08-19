#include "../nrc/philo.h"

void get_error()
{
    write(2,">>>>> number of Arguments are not correct <<<<<\n", 49);
    write(2,"u should set just\n[number_of_philosophe]\n",42);
    write(2,"[time_to_die]\n[time_to_sleep]\n[number_of_times_each",52);
    write(2,"_philosopher_must_eat] >>> [opsioneel]\n",40);
}


void print_philo_data(t_philo_data *data)
{
    if (!data)
    {
        printf("t_philo_data is NULL\n");
        return;
    }
    printf("------ Philosopher Data ------\n");
    printf("Number of philosophers              : %d\n", data->number_of_philosophe);
    printf("Time to die (ms)                    : %d\n", data->time_to_die);
    printf("Time to eat (ms)                    : %d\n", data->time_to_eat);
    printf("Time to sleep (ms)                  : %d\n", data->time_to_sleep);
    printf("Number of times each must eat       : %d\n", data->number_of_times_each_philosopher_must_eat);
    printf("-----------------------------------\n");
}


int main(int ac , char *av[])
{
    t_philo_data *philo_data;

    philo_data = malloc(sizeof(t_philo_data));
    if (ac == 5 || ac == 6)
    {
        if(parsing_philo_data(av + 1 , philo_data))
        {
            write(2,">>>>> set only Numbers <<<<<\n", 30);
            return 1;
        }
    }
    else{
        free(philo_data);
        get_error();
        return 1;
    }
    print_philo_data(philo_data);
    return 0;
}
