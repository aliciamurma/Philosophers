/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:30:11 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/27 17:09:02 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

/**
 * @brief Action of print
 * 
 * @param str 
 * @param philo 
 */
void	ft_print(char *str, t_philo *philo)
{
	long long int	time;

	time = ft_time() - philo->time_start;
	sem_wait(philo->print);
	printf("%lld	the philo	%d	%s\n", time, philo->id_philo, str);
	sem_post(philo->print);
}
