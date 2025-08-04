/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:11:44 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/04 14:21:20 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

int	ft_checkarg(int argc, char** argv, t_params *params)
{
	int i;

	i = 1;
	if (argc != 5 && argc != 6)
		return(fprintf(stderr, "Error: wrong number of arguments\n"), 0);
	while(i < argc)
	{
		if (!is_number(argv[i]))
			return(fprintf(stderr, "Error: invalid argument (not a positive number)\n"), 0);
		i++;
	}
	params->nb_philos = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		params->nb_must_eat = ft_atoi(argv[5]);
	else
		params->nb_must_eat = -1;
	if (params->nb_philos < 1 || params->time_to_die <= 0
		|| params->time_to_eat <= 0 || params->time_to_sleep <= 0
		|| (argc == 6 && params->nb_must_eat <= 0))
		return (fprintf(stderr, "Error: invalid argument value\n"), 0);
	return(1);
}
