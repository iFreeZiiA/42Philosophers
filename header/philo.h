/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:00:00 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/18 17:37:06 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int		is_number(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		ft_checkarg(int argc, char **argv, t_params *params);
int		init_data(t_data *data, t_params *params);
void	cleanup_data(t_data *data);
void	*philo_routine(void *arg);
int		philo_thread(t_data *data);
long	get_time_in_ms(void);
void	philo_sleep(t_philo *philo, int ms);
void	*monitor_death(void *arg);
void	print_action(t_philo *philo, char *str);
long	get_time_since_start(t_data *data);
int		get_stop_simulation(t_data *data);
void	set_stop_simulation(t_data *data);
void	*handle_one_philo(t_philo *philo);

#endif