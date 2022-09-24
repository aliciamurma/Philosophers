/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:16:31 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/24 21:42:48 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

/**
 * @brief Assign the given data
 * 
 * @param data 
 * @param argv 
 */
int	ft_init_data(t_data *data, char **argv)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->num_times_eat = -1;
	if (argv[5])
	{
		if (argv[5] == 0)
		{
			printf("Error\nRutina realizada antes de comenzar\n");
			return (-1);
		}
		data->num_times_eat = ft_atoi(argv[5]);
	}
	return (0);
}

/**
 * @brief Init the semaphor for: fork, print and the last print
 * It is need to create one fork semaphore for each num of philos
 * Primero eliminamos el semáforo en caso de que estuviese creado de antes
 * 
 * 
 * @param name 
 * @param value 
 * @return int 
 */
int	ft_init_semaphores(t_philo *philo)
{
	sem_unlink("sem_print");
	sem_unlink("sem_eating");
	sem_unlink("sem_fork");
	philo->print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	philo->eating = sem_open("sem_eating", O_CREAT | O_EXCL, 0644, 1);
	philo->fork = sem_open("sem_fork", O_CREAT | O_EXCL, 0644, philo->num_philos);
	if (philo->print == SEM_FAILED || philo->fork == SEM_FAILED || philo->eating == SEM_FAILED)
	{
		printf("Error\nSemáforos pochos\n");
	}
	philo->time_start = ft_time() + (50 * philo->num_philos);
	return (1);
}

/**
 * @brief Init all the philosophers with their data
 * Create a semaphor for the fork, print the actions,
 * the death and number of times that each philo must eat
 * 
 * @param data 
 * @return int 
 */
int	ft_init_philo(t_data *data, t_philo *philo)
{
	philo->num_philos = data->num_philos;
	philo->time_die = data->time_die;
	philo->time_eat = data->time_eat;
	philo->time_sleep = data->time_sleep;
	philo->num_times_eat = data->num_times_eat;
	philo->need_eat = philo->num_times_eat;
	philo->time_actual = data->time_actual;
	philo->last_eat = philo->time_start;
	philo->status = 0;
	return (0);
}

/**
 * @brief Init everything
 * 
 * @param data 
 * @param argv 
 * @return int 
 */
int	ft_init(t_data *data, t_philo *philo, char **argv)
{
	if (ft_init_data(data, argv) == -1)
		return (-1);
	if (ft_init_philo(data, philo) == -1)
	{
		return (-1);
	}
	if (ft_init_semaphores(philo) == -1)
	{
		return (-1);
	}
	return (0);
}
