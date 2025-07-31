#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "struct.h"

int		is_number(const char *str);
int		ft_atoi(const char *str);
int		ft_checkarg(int argc, char** argv, t_params *params);
int		init_data(t_data *data, t_params *params);
void	*philo_routine(void *arg);
int		philo_thread(t_data *data);
long	get_time_in_ms(void);
void	philo_sleep(t_philo *philo, int ms);
void	*monitor_death(void *arg);
void	print_action(t_philo *philo, char *str);
long	get_time_since_start(t_data *data);

#endif