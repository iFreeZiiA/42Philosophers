/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:00:00 by alearroy          #+#    #+#             */
/*   Updated: 2025/08/12 16:02:21 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_params
{
	int		nb_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_must_eat;
}	t_params;

typedef struct s_data
{
	t_params		params;
	long			start_time;
	int				stop_simulation;
	int				finished_philos;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	meal_mutex;
	struct s_philo	*philos;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	int				done_eating;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

#endif
