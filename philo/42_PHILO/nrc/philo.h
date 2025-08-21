#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define THINKING 1
# define EATING 2
# define SLEEPING 3
# define TOOK_FORK 4
# define DIED 5

typedef struct s_philo	t_philo;

typedef struct s_data
{
	pthread_mutex_t		*fork;
	pthread_mutex_t		print;
	pthread_mutex_t		meals;
	pthread_mutex_t		death;
	pthread_mutex_t		turn;
	pthread_t			moniteur;
	int					number_of_philosophe;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					is_died;
	int					must_eat;
	int					current_turn;
	long long			start_time;
	int					all_ate;
	t_philo				*philo;
}						t_data;

typedef struct s_philo
{
	int					id;
	int					left_fork;
	int					right_fork;
	int					meals_eaten;
	long				last_meal;
	pthread_t			thread;
	t_data				*data;
}						t_philo;

int						parsing_philo_data(char **av, t_data *philo_data);
void					print_state(t_philo *philo, int state);
long long				get_time(void);
void					custom_sleep(int time_ms, t_philo *philo);
void					take_fork(t_philo *philo);
void					puts_fork(t_philo *philo);
void					sleeping_then_think(t_philo *philo);
int						check_death(t_philo *philo);
void					*if_even_rotine(void *arg);
void					*if_odd_rotine(void *arg);
void					*monitor_routine(void *arg);
void					cleanup(t_data *data);
int  					dinner(t_data *data);
void 					leonardo_da_vinci_dinner(t_data *data);
#endif