/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:02:48 by alearroy          #+#    #+#             */
/*   Updated: 2025/07/28 18:32:47 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	if (philo->data->stop_simulation)
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
	if (philo->data->stop_simulation)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->print_mutex);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->data->print_mutex);
	philo_sleep(philo->data->params.time_to_eat);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

static void	philo_sleep_and_think(t_philo *philo)
{
	if (philo->data->stop_simulation)
		return ;
	print_action(philo, "is sleeping");
	philo_sleep(philo->data->params.time_to_sleep);
	if (philo->data->stop_simulation)
		return ;
	print_action(philo, "is thinking");
}

void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (!philo->data->stop_simulation)
	{
		philo_eat(philo);
		philo_sleep_and_think(philo);
	}
	return (NULL);
}
