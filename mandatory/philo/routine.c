/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:02:48 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/05 16:06:54 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->print_mutex);
	philo->last_meal = get_time_in_ms() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->print_mutex);
	philo->meals_eaten++;
	philo_sleep(philo, philo->data->params.time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	philo_sleep_and_think(t_philo *philo)
{
	if (philo->data->stop_simulation)
		return ;
	print_action(philo, "is sleeping");
	philo_sleep(philo, philo->data->params.time_to_sleep);
	if (philo->data->stop_simulation)
		return ;
	print_action(philo, "is thinking");
}

void	*handle_one_philo(t_philo *philo)
{
	t_params	*params = &philo->data->params;

	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	philo_sleep(philo, params->time_to_die);
	print_action(philo, "died");
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

int	get_stop_simulation(t_data *data)
{
	int stop;

	pthread_mutex_lock(&data->stop_mutex);
	stop = data->stop_simulation;
	pthread_mutex_unlock(&data->stop_mutex);
	return (stop);
}

void	*philo_routine(void *arg)
{
	t_philo *philo;
	t_params *params;

	philo = (t_philo *)arg;
	params = &philo->data->params;
	if (params->nb_philos == 1)
		return (handle_one_philo(philo));
	while (!get_stop_simulation(philo->data))
	{
		philo_eat(philo);
		philo_sleep_and_think(philo);
	}
	return (NULL);
}
