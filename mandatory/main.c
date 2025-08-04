/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:58:56 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/04 14:11:12 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int main(int argc, char **argv)
{
	t_params	params;
	t_data		data;
	int			i;

	if(!ft_checkarg(argc, argv, &params))
		return(EXIT_FAILURE);
	if(!init_data(&data, &params))
		return(EXIT_FAILURE);
	printf("Philosophes :\n");
	i = 0;
	while (i < data.params.nb_philos)
	{
		printf("Philo %d : left %p, right %p\n",
			data.philos[i].id,
			(void *)data.philos[i].left_fork,
			(void *)data.philos[i].right_fork);
		i++;
	}
	if (!philo_thread(&data))
		return (EXIT_FAILURE);
	return(0);
}

/* if (nb_philos == 1)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	// Attend le time_to_die
	philo_sleep(philo, params->time_to_die);
	print_action(philo, "died");
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
} */