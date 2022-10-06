/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:36:06 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/06 17:44:10 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_delete(t_data *data)
{
	int	count;

	count = 0;
	pthread_mutex_unlock(&data->m_print);
	pthread_mutex_unlock(data->m_forks);
	pthread_mutex_unlock(&data->m_death);
	pthread_mutex_destroy(&data->m_death);
	pthread_mutex_destroy(&data->m_print);
	while (count < data->num_philos)
	{
		pthread_mutex_destroy(&data->m_forks[count]);
		count++;
	}
	free(data->philo);
	free(data->m_forks);
	free(data);
}
