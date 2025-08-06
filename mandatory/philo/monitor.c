/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:13:35 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/06 15:39:49 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	*monitor_death(void *arg)
{
	t_data	*data;
	int		i;
	long now;

	data = (t_data *)arg;
	while (!data->stop_simulation)
	{
		i = 0;
		while (i < data->params.nb_philos)
		{
			now = get_time_in_ms() - data->start_time;
/* 			printf("philo[%d] : %ld ms since last meal (to die: %d)\n", i, get_time_since_start(data) - data->philos[i].last_meal, data->params.time_to_die);
 */			pthread_mutex_lock(&data->print_mutex);
			if (now - data->philos[i].last_meal > data->params.time_to_die)
			{
				pthread_mutex_lock(&data->stop_mutex);
				data->stop_simulation = 1;
				pthread_mutex_unlock(&data->stop_mutex); 
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
