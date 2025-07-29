/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:12 by alearroy          #+#    #+#             */
/*   Updated: 2025/07/28 18:27:39 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->params.nb_philos);
	if(!data->forks)
		return(0);
	i = 0;
	while(i < data->params.nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return(0);
		i++;
	}
	return(1);
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
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = get_time_in_ms();
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->params.nb_philos];
		data->philos[i].data = data;
		i++;
	}
	return(1);
}

int	init_data(t_data *data, t_params *params)
{
	data->params = *params;
	data->stop_simulation = 0;
	if (!init_forks(data))
		return (0);
	if (!init_philos(data))
		return (0);
	if (pthread_mutex_init(&data->print_mutex, NULL))
		return (0);
	return (1);
}