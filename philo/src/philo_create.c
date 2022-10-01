/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:48:00 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/01 17:59:36 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Realizamos un bucle infinito para que completen la rutina
 * a no ser que mueran o coman X n- de veces
 * 
 * @param data 
 */
void	ft_no_deaths(t_data *data)
{
	while (data->death == 0)
	{
		if (ft_routine_completed(data) == 0)
		{
			printf("All the philos have eaten enough\n");
			break ;
		}
		if (ft_die(data) == 0)
		{
			break ;
		}
	}
}

/**
 * @brief Create the pthreads. 1 pthread by philo
 * https://www.youtube.com/watch?v=NAKrOZCcJ4A
 * Necesitamos hacer un usleep de 1 cuando se crean los filósofos
 * para que funcione a tiempos cortos. Si no, los tiempos cortos 
 * aparecerán a tiempos ilógicos
 * Necesitamos un bucle infinito para que no se cierre cuando acabe un proceso
 * 
 * @param data 
 * @return int 
 */
int	ft_create_pthread(t_data *data)
{
	pthread_t	*pthread;
	int			count;

	count = 0;
	pthread = (pthread_t *)malloc(sizeof(pthread_t) * data->num_philos);
	if (!pthread)
		return (-1);
	while (count < data->num_philos)
	{
		if (pthread_create(&pthread[count], NULL,
				&ft_start_routine, &data->philo[count]) != 0)
			return (-1);
		count++;
	}
	ft_no_deaths(data);
	count = 0;
	while (pthread[count])
	{
		pthread_join(pthread[count], NULL);
		count++;
	}
	free (pthread);
	return (0);
}
