/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:19:34 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/30 16:03:15 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief The philos eats
 * (1) Miramos que no haya muertos
 * (2) Bloqueamos el tenedor derecho
 * (3) Bloqueamos el tenedor izquierdo
 * (4) Cogemos el tiempo de la ultima comida
 * (nos aseguramos de que no esta muerto por inanición)
 * (5) Come
 * (2) Desbloqueamos el tenedor derecho
 * (3) Desbloqueamos el tenedor izquierdo
 * 
 * @param philo 
 * @return int 
 */
int	ft_eat(t_philo *philo)
{
	if (philo->data->death != 0)
		return (-1);
	pthread_mutex_lock(&philo->data->m_forks[philo->left_fork]);
	ft_print_fork(philo);
	if (philo->data->num_philos == 1)
		ft_usleep(philo->data->time_die + 1);
	pthread_mutex_lock(&philo->data->m_forks[philo->right_fork]);
	ft_print_fork(philo);
	philo->last_eat = ft_time() - philo->data->time_start;
	ft_print_eat(philo);
	philo->need_eat++;
	ft_usleep(philo->data->time_eat);
	pthread_mutex_unlock(&philo->data->m_forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->m_forks[philo->right_fork]);
	return (0);
}

/**
 * @brief The philos sleep
 * 
 * @param philo 
 * @return int 
 */
int	ft_sleep(t_philo *philo)
{
	if (philo->data->death != 0)
		return (-1);
	ft_print_sleep(philo);
	ft_usleep(philo->data->time_sleep);
	return (0);
}

/**
 * @brief The philos think
 * 
 * @param philo 
 * @return int 
 */
int	ft_think(t_philo *philo)
{
	if (philo->data->death != 0)
		return (-1);
	ft_print_think(philo);
	return (0);
}

/**
 * @brief The routine that all the philos have to do
 * (1) Eat
 * (2) Sleep
 * (3) Think
 * Después desbloqueamos los tenedores, por si ha acabado la rutina
 * pero algún filósofo tiene los tenedores en la mano
 * 
 * @param arg 
 * @return void* 
 */
void	*ft_start_routine(void *arg)
{
	t_philo	*philo;
	int		count;

	philo = (t_philo *)arg;
	if (philo->name % 2 != 0)
		ft_usleep(philo->data->time_eat);
	philo->last_eat = (ft_time() - philo->data->time_start);
	count = 0;
	while (philo->data->death == 0)
	{
		if (ft_eat(philo) == -1 || ft_sleep(philo) == -1
			|| ft_think(philo) == -1)
			break ;
	}
	count = 0;
	while (count < philo->data->num_philos)
	{
		pthread_mutex_unlock(&philo->data->m_forks[count]);
		count++;
	}
	return (0);
}
