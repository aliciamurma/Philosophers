/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:19:34 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/30 16:39:25 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

/**
 * @brief The philos eats
 * (1) Lock the semaphors
 * (2) Take the time of last eating
 * (3) Eat
 * (4) Unlock the semaphors
 * OJO!! Check what happens if there is only 1 philo
 * 
 * @param philo 
 * @return int 
 */
void	ft_eat(t_philo *philo)
{
	sem_wait(philo->eating);
	sem_wait(philo->fork);
	ft_print_fork("has taken a fork", philo);
	if (philo->num_philos == 1)
		ft_usleep(philo->time_die + 1);
	sem_wait(philo->fork);
	ft_print_fork("has taken a fork", philo);
	philo->last_eat = ft_time() - philo->time_start;
	ft_print_eat("is eating", philo);
	philo->num_times_eat--;
	if (philo->num_times_eat == 0)
	{
		sem_post(philo->fork);
		sem_post(philo->fork);
		sem_post(philo->eating);
		exit (1);
	}
	sem_post(philo->eating);
	ft_usleep(philo->time_eat);
	sem_post(philo->fork);
	sem_post(philo->fork);
}

/**
 * @brief The philos sleep
 * 
 * @param philo 
 * @return int 
 */
void	ft_sleep(t_philo *philo)
{
	ft_print_sleep("is sleeping", philo);
	ft_usleep(philo->time_sleep);
}

/**
 * @brief The philos think
 * 
 * @param philo 
 * @return int 
 */
void	ft_think(t_philo *philo)
{
	ft_print_think("is thinking", philo);
}

/**
 * @brief The routine that all the philos have to do
 * (1) Eat
 * (2) Sleep
 * (3) Think
 * 
 * @param philo 
 * @return int 
 */
void	*ft_routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	ft_usleep((philo->time_eat / 3) * (philo->num_philos % 2));
	philo->last_eat = (ft_time() - philo->time_start);
	while (philo->num_times_eat != 0)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	if (philo->num_times_eat == 0)
		exit (1);
	return (NULL);
}

/**
 * @brief It's the main of the soon
 * It is need to create a pthread for each philo, which will
 * make all the routine
 * In a infinite while we check if a philo dies (status = 1)
 * or if completes the routine (status = 2)
 * In both cases, the routine has to end
 * The usleep function is necessary to make that all the philos 
 * start at the same time
 * 
 * @param arg 
 * @return void* 
 */
int	ft_start_routine(t_philo *philo, int id)
{
	pthread_t	monitor;

	philo->id_philo = id + 1;
	while (philo->time_start > ft_time())
		ft_usleep(5);
	if (pthread_create(&monitor, NULL, ft_routine, philo) != 0)
	{
		sem_wait(philo->print);
		printf("Error\nHilos pachuchos\n");
		sem_close(philo->print);
		exit (1);
	}
	while (philo->num_times_eat != 0)
	{
		if (philo->time_die <= ft_time_death(philo))
		{
			sem_wait(philo->print);
			printf("%lld\tthe philo	%d\tdied\n",
				ft_time() - philo->time_start, philo->id_philo);
			exit (0);
		}
	}
	pthread_join(monitor, NULL);
	return (1);
}
