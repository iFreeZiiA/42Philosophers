/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:13:35 by alearroy          #+#    #+#             */
/*   Updated: 2025/07/31 17:57:27 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	*monitor_death(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!data->stop_simulation)
	{
		i = 0;
		while (i < data->params.nb_philos)
		{
			pthread_mutex_lock(&data->print_mutex);
			if (get_time_in_ms() - data->philos[i].last_meal > data->params.time_to_die)
			{
				data->stop_simulation = 1;
				pthread_mutex_unlock(&data->print_mutex);
				print_action(&data->philos[i], "died");
				return (NULL);
			}
			pthread_mutex_unlock(&data->print_mutex);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}