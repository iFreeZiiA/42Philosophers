/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:13:35 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/12 16:38:46 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	print_action(t_philo *philo, char *str)
{
	long	time;
	int		should_print;

	pthread_mutex_lock(&philo->data->stop_mutex);
	should_print = !philo->data->stop_simulation || !ft_strcmp(str, "died");
	pthread_mutex_unlock(&philo->data->stop_mutex);
	if (should_print)
	{
		time = get_time_since_start(philo->data);
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%ld %d %s\n", time, philo->id, str);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
}

static int	check_all_finished(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->finish_mutex);
	result = (data->params.nb_must_eat > 0
			&& data->finished_philos >= data->params.nb_philos);
	if (result)
	{
		pthread_mutex_lock(&data->stop_mutex);
		data->stop_simulation = 1;
		pthread_mutex_unlock(&data->stop_mutex);
	}
	pthread_mutex_unlock(&data->finish_mutex);
	return (result);
}

static int	check_philosopher_death(t_data *data, int i)
{
	long	now;
	int		is_dead;

	now = get_time_in_ms() - data->start_time;
	pthread_mutex_lock(&data->meal_mutex);
	is_dead = (now - data->philos[i].last_meal > data->params.time_to_die);
	pthread_mutex_unlock(&data->meal_mutex);
	if (is_dead)
	{
		pthread_mutex_lock(&data->stop_mutex);
		data->stop_simulation = 1;
		pthread_mutex_unlock(&data->stop_mutex);
		pthread_mutex_lock(&data->print_mutex);
		printf("%ld %d died\n", now, data->philos[i].id);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_death(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!data->stop_simulation)
	{
		if (check_all_finished(data))
			return (NULL);
		i = 0;
		while (i < data->params.nb_philos && !data->stop_simulation)
		{
			if (check_philosopher_death(data, i))
				return (NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
