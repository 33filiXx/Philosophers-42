#ifndef PHILO_H
#define PHILO_H

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

typedef struct  s_philo_data
{
    int number_of_philosophe;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
} t_philo_data;

int parsing_philo_data(char **av  , t_philo_data *philo_data);

#endif