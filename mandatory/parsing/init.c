/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:12 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/12 16:38:48 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->params.nb_philos);
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->params.nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

static int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->params.nb_philos);
	if (!data->philos)
		return (0);
	i = 0;
	while (i < data->params.nb_philos)
	{
		data->philos[i].done_eating = 0;
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = get_time_in_ms() - data->start_time;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1)
			% data->params.nb_philos];
		data->philos[i].data = data;
		i++;
	}
	return (1);
}

int	init_data(t_data *data, t_params *params)
{
	data->params = *params;
	data->stop_simulation = 0;
	data->start_time = get_time_in_ms();
	data->finished_philos = 0;
	data->forks = NULL;
	data->philos = NULL;
	if (pthread_mutex_init(&data->finish_mutex, NULL))
		return (0);
	if (pthread_mutex_init(&data->stop_mutex, NULL))
		return (0);
	if (pthread_mutex_init(&data->meal_mutex, NULL))
		return (0);
	if (!init_forks(data))
		return (0);
	if (!init_philos(data))
		return (0);
	if (pthread_mutex_init(&data->print_mutex, NULL))
		return (0);
	return (1);
}

void	cleanup_data(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->params.nb_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
	pthread_mutex_destroy(&data->finish_mutex);
	pthread_mutex_destroy(&data->stop_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}
