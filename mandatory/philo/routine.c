/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:02:48 by alearroy          #+#    #+#             */
/*   Updated: 2025/07/22 18:44:26 by alearroy         ###   ########.fr       */
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

static void	philo_sleep(int ms)
{
	long	start;

	start = get_time_in_ms();
	while (get_time_in_ms() - start < ms)
		usleep(100);
}

void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (!philo->data->stop_simulation)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		printf("%ld %d has taken a fork\n", get_time_in_ms(), philo->id);
		printf("%ld %d has taken a fork\n", get_time_in_ms(), philo->id);
		printf("%ld %d is eating\n", get_time_in_ms(), philo->id);
		pthread_mutex_lock(&philo->data->print_mutex);
		philo->last_meal = get_time_in_ms();
		pthread_mutex_unlock(&philo->data->print_mutex);
		philo_sleep(philo->data->params.time_to_eat);
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		printf("%ld %d is sleeping\n", get_time_in_ms(), philo->id);
		philo_sleep(philo->data->params.time_to_sleep);
		printf("%ld %d is thinking\n", get_time_in_ms(), philo->id);
	}
	return (NULL);
}
