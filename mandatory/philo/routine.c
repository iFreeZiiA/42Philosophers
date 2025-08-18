/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:02:48 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/18 17:37:06 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static void	update_meal_status(t_philo *philo)
{
	if (!philo->done_eating && philo->data->params.nb_must_eat > 0
		&& philo->meals_eaten >= philo->data->params.nb_must_eat)
	{
		pthread_mutex_lock(&philo->data->finish_mutex);
		philo->data->finished_philos++;
		philo->done_eating = 1;
		pthread_mutex_unlock(&philo->data->finish_mutex);
	}
}

static void	get_forks_order(t_philo *philo, pthread_mutex_t **first,
		pthread_mutex_t **second)
{
	if (philo->id % 2 == 0)
	{
		*first = philo->right_fork;
		*second = philo->left_fork;
	}
	else
	{
		*first = philo->left_fork;
		*second = philo->right_fork;
	}
}

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (get_stop_simulation(philo->data))
		return ;
	get_forks_order(philo, &first_fork, &second_fork);
	pthread_mutex_lock(first_fork);
	print_action(philo, "has taken a fork");
	if (get_stop_simulation(philo->data))
	{
		pthread_mutex_unlock(first_fork);
		return ;
	}
	pthread_mutex_lock(second_fork);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal = get_time_in_ms() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	philo->meals_eaten++;
	philo_sleep(philo, philo->data->params.time_to_eat);
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);
	update_meal_status(philo);
}

static void	philo_sleep_and_think(t_philo *philo)
{
	if (get_stop_simulation(philo->data))
		return ;
	print_action(philo, "is sleeping");
	philo_sleep(philo, philo->data->params.time_to_sleep);
	if (get_stop_simulation(philo->data))
		return ;
	print_action(philo, "is thinking");
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	t_params	*params;

	philo = (t_philo *)arg;
	params = &philo->data->params;
	if (params->nb_philos == 1)
		return (handle_one_philo(philo));
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!get_stop_simulation(philo->data) && !philo->done_eating)
	{
		philo_eat(philo);
		if (!philo->done_eating)
			philo_sleep_and_think(philo);
	}
	return (NULL);
}
