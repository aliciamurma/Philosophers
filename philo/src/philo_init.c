/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:16:31 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/03 17:31:06 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
	if (argv[5])
	{
		data->num_times_eat = ft_atoi(argv[5]);
		if (ft_atoi(argv[5]) == 0)
		{
			printf("Error\nRutina realizada antes de comenzar\n");
			return (-1);
		}
	}
	if (data->num_philos == 0 || data->time_die == 0
		|| data->time_eat == 0 || data->time_sleep == 0)
	{
		printf("Error\n");
		return (-1);
	}
	return (0);
}

/**
 * @brief Init the muted forks
 * If atributes is specified as NULL, all attributes are set 
 * to the default mutex attributes for the newly created mutex
 * 
 * @param data 
 * @return int 
 */
int	ft_init_mutex(t_data *data)
{
	int	count;

	count = 0;
	pthread_mutex_init(&data->m_print, NULL);
	pthread_mutex_init(&data->m_death, NULL);
	data->m_forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->m_forks)
		return (-1);
	while (count < data->num_philos)
	{
		if (pthread_mutex_init(&data->m_forks[count], NULL) != 0)
			return (-1);
		count++;
	}
	return (0);
}

/**
 * @brief Init all the philosophers with their data
 * 
 * @param data 
 * @return int 
 */
int	ft_init_philos(t_data *data)
{
	int	count;

	count = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philo)
		return (-1);
	while (count < data->num_philos)
	{
		data->philo[count].name = count + 1;
		data->philo[count].left_fork = count + 1;
		data->philo[count].right_fork = count;
		data->philo[count].data = data;
		count++;
	}
	data->philo[0].right_fork = count;
	return (0);
}

/**
 * @brief Init everything
 * 
 * @param data 
 * @param argv 
 * @return int 
 */
int	ft_init(t_data *data, char **argv)
{
	if (ft_init_data(data, argv) == -1)
		return (-1);
	if (ft_init_mutex(data) == -1)
	{
		return (-1);
	}
	if (ft_init_philos(data) == -1)
	{
		return (-1);
	}
	return (0);
}
