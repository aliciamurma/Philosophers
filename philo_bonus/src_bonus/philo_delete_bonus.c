/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_delete_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:02:46 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/24 21:46:52 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

void	ft_delete_semaphores(t_philo *philo)
{
	sem_close(philo->fork);
	sem_close(philo->print);
	sem_close(philo->eating);
}

void	ft_delete(t_philo *philo, t_data *data)
{
	ft_delete_semaphores(philo);
	ft_end_philo(data);
	free(data->pid);
	data->pid = NULL;
}
