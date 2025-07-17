/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:58:56 by alearroy          #+#    #+#             */
/*   Updated: 2025/07/17 16:59:00 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int main(int argc, char **argv)
{
	t_params params;

	if(!ft_checkarg(argc, argv, &params))
		return(EXIT_FAILURE);
	printf("Philos: %d, Die: %d, Eat: %d, Sleep: %d, Meals: %d\n",
		params.nb_philos, params.time_to_die, params.time_to_eat,
		params.time_to_sleep, params.nb_must_eat);
	return(0);
}