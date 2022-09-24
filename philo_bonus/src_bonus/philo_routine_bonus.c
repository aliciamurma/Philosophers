/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:19:34 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/24 19:07:00 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

/**
 * @brief The philos eats
 * (1) Miramos que no estén muertos ni hayan completado la rutina
 * (2) Bloqueamos los tenedores
 * (3) Cogemos el tiempo de la ultima comida
 * (4) Come
 * (5) Desbloqueamos los tenedores
 * 
 * @param philo 
 * @return int 
 */
void	ft_eat(t_philo *philo)
{
	sem_wait(philo->eating);
	sem_wait(philo->fork);
	ft_print("has taken a fork", philo);
	if (philo->data->num_philos == 1)
		ft_usleep(philo->data->time_die + 1);
	sem_wait(philo->fork);
	ft_print("has taken a fork", philo);
	sem_post(philo->eating);
	philo->last_eat = ft_time() - philo->data->time_start;
	ft_print("is eating", philo);
	philo->need_eat++;
	if (philo->need_eat == philo->data->num_times_eat)
	{
		sem_post(philo->fork);
		sem_post(philo->fork);
		exit (2);
	}
	ft_usleep(philo->data->time_eat);
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
	ft_print("is sleeping", philo);
	ft_usleep(philo->data->time_sleep);
}

/**
 * @brief The philos think
 * 
 * @param philo 
 * @return int 
 */
void	ft_think(t_philo *philo)
{
	ft_print("is thinking", philo);
}

/**
 * @brief The routine that all the philos have to do
 * (1) Eat
 * (2) Sleep
 * (3) Think
 * Aqui hacer un usleep de la mitad me funciona para pocos filosofos
 * Para muchos se vuelve loco. Mejor hacer semaforo
 * 
 * @param philo 
 * @return int 
 */
void	*ft_routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	ft_usleep(philo->data->time_eat / 2);
	philo->last_eat = (ft_time() - philo->data->time_start);
	while (philo->need_eat != philo->data->num_times_eat)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	if (philo->need_eat == philo->data->num_times_eat)
		exit (1);
	return (NULL);
}

/**
 * @brief Es el main del hijo
 * Creamos un hilo para cada filósofo, que hará su rutina
 * En un bucle infinito para cada filósofo vamos a checkear que 
 * ninguno haya muerto (status = 1) o haya completado su rutina (status = 2)
 * En ambos casos, su rutina debe finalizar
 * 
 * Tenemos que poner un usleep porque si no los tiempos no funcionan
 * 
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
		printf("Error\nHilos pachuchos\n");
		exit (0);
	}
	ft_usleep(200);
	while (philo->status == 0)
	{
		if (philo->data->time_die < (long long int)((ft_time()
				- philo->data->time_start) - philo->last_eat))
		{
			printf("TIME START IS %lld AND MY LAST EAT WAS %lld\n", philo->data->time_start, philo->last_eat);
			printf("ENTRO EN MUERTE\n");
			philo->status = 1;
			break ;
		}
		if (philo->data->num_times_eat <= philo->need_eat)
		{
			printf("ENTRO EN COMPLETO\n");
			philo->status = 2;
			break ;
		}
	}
	pthread_join(monitor, NULL);
	exit (0);
}
