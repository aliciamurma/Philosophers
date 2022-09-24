/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:30:14 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/23 14:00:18 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Check if the routine is completed acording with the number
 * of times that each philo must eat
 * 
 * @param data 
 * @return int 
 */
int	ft_routine_completed(t_data *data)
{
	int	count;
	int	finish;

	count = 0;
	finish = 0;
	if (data->num_times_eat == 0)
		return (1);
	while (count < data->num_philos)
	{
		if (data->philo[count].need_eat >= data->num_times_eat)
			finish++;
		else
			break ;
		count++;
	}
	if (finish >= data->num_philos)
	{
		data->death = 1;
		pthread_mutex_lock(&data->m_print);
		pthread_mutex_lock(data->m_forks);
		return (0);
	}
	return (1);
}

/**
 * @brief Check if the philos die
 * 
 * @param data 
 * @return int 
 */
int	ft_die(t_data *data)
{
	int	count;

	count = 0;
	while (count < data->num_philos)
	{
		if (data->time_die < (long long int)((ft_time() - data->time_start)
			- data->philo[count].last_eat))
		if (data->time_die < (long long int)((ft_time() - data->time_start)
			- data->philo[count].last_eat))
		{
			pthread_mutex_lock(&data->m_death);
			printf("EL TIEMPO DE ULTIMA COMIDA FUE  %lld\n", data->philo[count].last_eat);
			ft_print_die(&data->philo[count]);
			// pthread_mutex_lock(&data->m_print);
			pthread_mutex_lock(data->m_forks);
			data->death = 1;
			return (0);
		}
		count++;
	}
	return (1);
}
