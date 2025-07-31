/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:41:21 by alearroy          #+#    #+#             */
/*   Updated: 2025/07/31 17:41:44 by alearroy         ###   ########.fr       */
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
	while (!philo->data->stop_simulation && get_time_in_ms() - start < ms)
		usleep(100);
}

void	print_action(t_philo *philo, char *str)
{
	long	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->stop_simulation)
	{
		time = get_time_since_start(philo->data);
		printf("%ld %d %s\n", time, philo->id, str);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}