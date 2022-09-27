/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:30:11 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/27 20:09:00 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

/**
 * @brief Action of print
 * 
 * @param str 
 * @param philo 
 */
void	ft_print_fork(char *str, t_philo *philo)
{
	long long int	time;

	time = ft_time() - philo->time_start;
	sem_wait(philo->print);
	printf("\e[1;97m""%lld\tthe philo\t%d\t%s\n""\e[0m", time, philo->id_philo, str);
	sem_post(philo->print);
}

void	ft_print_sleep(char *str, t_philo *philo)
{
	long long int	time;

	time = ft_time() - philo->time_start;
	sem_wait(philo->print);
	printf("\e[1;96m""%lld\tthe philo\t%d\t%s\n""\e[0m", time, philo->id_philo, str);
	sem_post(philo->print);
}

void	ft_print_eat(char *str, t_philo *philo)
{
	long long int	time;

	time = ft_time() - philo->time_start;
	sem_wait(philo->print);
	printf("\e[1;95m""%lld\tthe philo\t%d\t%s\n""\e[0m", time, philo->id_philo, str);
	sem_post(philo->print);
}

void	ft_print_think(char *str, t_philo *philo)
{
	long long int	time;

	time = ft_time() - philo->time_start;
	sem_wait(philo->print);
	printf("\e[1;91m""%lld\tthe philo\t%d\t%s\n""\e[0m", time, philo->id_philo, str);
	sem_post(philo->print);
}
