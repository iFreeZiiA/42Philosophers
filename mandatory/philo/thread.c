/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:17:14 by alearroy          #+#    #+#             */
/*   Updated: 2025/07/28 17:29:10 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

int philo_thread(t_data *data)
{
	int	i;
	pthread_t	monitor;

	i = 0;
	while (i < data->params.nb_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine, &data->philos[i]))
		{
			printf("Error thread creation %d\n", i);
			return (0);
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_death, &data))
	{
		printf("Erreur création thread superviseur\n");
		return (EXIT_FAILURE);
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < data->params.nb_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	return (1);
}