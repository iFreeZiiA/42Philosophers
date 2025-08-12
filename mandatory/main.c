/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:58:56 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/12 16:38:52 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_params	params;
	t_data		data;

	if (!ft_checkarg(argc, argv, &params))
		return (EXIT_FAILURE);
	if (!init_data(&data, &params))
	{
		cleanup_data(&data);
		return (EXIT_FAILURE);
	}
	if (!philo_thread(&data))
	{
		cleanup_data(&data);
		return (EXIT_FAILURE);
	}
	cleanup_data(&data);
	return (0);
}
