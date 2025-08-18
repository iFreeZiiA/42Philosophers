/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:17:14 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/18 17:37:06 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->params.nb_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	philo_thread(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < data->params.nb_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				philo_routine, &data->philos[i]))
		{
			printf("Error thread creation %d\n", i);
			return (0);
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_death, data))
	{
		printf("Erreur création thread superviseur\n");
		return (0);
	}
	pthread_join(monitor, NULL);
	join_threads(data);
	return (1);
}
