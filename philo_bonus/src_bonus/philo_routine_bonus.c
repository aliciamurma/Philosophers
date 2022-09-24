/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:19:34 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/24 21:48:12 by amurcia-         ###   ########.fr       */
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
	if (philo->num_philos == 1)
		ft_usleep(philo->time_die + 1);
	sem_wait(philo->fork);
	ft_print("has taken a fork", philo);
	philo->last_eat = ft_time() - philo->time_start;
	ft_print("is eating", philo);
	philo->need_eat--;
	if (philo->need_eat == 0)
	{
		sem_post(philo->fork);
		sem_post(philo->fork);
		exit (2);
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
	ft_print("is sleeping", philo);
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

	printf("hola\n");
	philo = (t_philo *)void_philo;
	ft_usleep(philo->time_eat / 2);
	philo->last_eat = (ft_time() - philo->time_start);
	while (philo->need_eat != 0)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	if (philo->need_eat == 0)
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
		sem_wait(philo->print);
		printf("Error\nHilos pachuchos\n");
		sem_close(philo->print);
		exit (1);
	}
	while (philo->need_eat != 0)
	{
		if (philo->time_die < (ft_time() - philo->time_start - philo->last_eat))
		{
			philo->status = 1;
			sem_wait(philo->print);
			printf("The philo %d died\n", philo->id_philo);
			philo->status = 1;
			exit (1);
		}
		// if (philo->need_eat == 0)
		// {
		// 	sem_wait(philo->print);
		// 	printf("All the philos have eaten %lld times\n", philo->num_times_eat);
		// 	philo->status = 2;
		// 	break ;
		// }
	}
	pthread_join(monitor, NULL);
	return (1);
}
