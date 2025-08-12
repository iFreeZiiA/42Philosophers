/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:41:21 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/12 16:13:09 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

long	get_time_in_ms(void)
{
	struct timeval	tv;
	long			ms;

	if (gettimeofday(&tv, NULL))
		return (-1);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

long	get_time_since_start(t_data *data)
{
	long	now;

	now = get_time_in_ms();
	return (now - data->start_time);
}

void	philo_sleep(t_philo *philo, int ms)
{
	long	start;

	start = get_time_in_ms();
	while (!get_stop_simulation(philo->data) && get_time_in_ms() - start < ms)
		usleep(100);
}

int	get_stop_simulation(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->stop_mutex);
	stop = data->stop_simulation;
	pthread_mutex_unlock(&data->stop_mutex);
	return (stop);
}

void	*handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	philo_sleep(philo, philo->data->params.time_to_die);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}
