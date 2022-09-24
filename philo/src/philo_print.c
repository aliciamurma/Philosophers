/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:03:05 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/23 13:24:30 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Protect the printf so it does not overlap with other prints
 * Hacemos diferentes para que aparezcan de diferentes colores
 * Mutex: https://www.youtube.com/watch?v=faZEhIHdJx8
 * 
 * @param philo 
 */
void	ft_print_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf(BWHT"%lld the philo %d died \n"RESET,
			(ft_time() - philo->data->time_start), philo->name);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	ft_print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf(BLU"%lld the philo %d is sleeping \n"RESET,
			(ft_time() - philo->data->time_start), philo->name);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	ft_print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf(BCYN"%lld the philo %d has taken a fork\n"RESET,
			(ft_time() - philo->data->time_start), philo->name);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	ft_print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf(BRED"%lld the philo %d is eating \n"RESET,
			(ft_time() - philo->data->time_start), philo->name);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	ft_print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf(YEL"%lld the philo %d is thinking \n"RESET,
			(ft_time() - philo->data->time_start), philo->name);
	pthread_mutex_unlock(&philo->data->m_print);
}
