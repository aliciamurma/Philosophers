/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:50:15 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/24 21:46:59 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "../inc_bonus/philo_bonus.h"
#include <sys/wait.h>

/**
 * @brief Kill for each philo with their pid
 * Si alguno muere, mata a los demas con kill
 * 
 * @param data 
 */
int	ft_kill_all(t_data *data, pid_t pid)
{
	int	count;

	count = 0;
	while (count < data->num_philos)
	{
		if (data->pid[count] != pid)
			kill(data->pid[count], SIGKILL);
		count++;
	}
	return (1);
}

/**
 * @brief Check if the process has ended
 * Ponemos -1 y no el PID porque así mira cualquier pid y no uno en concreto
 * Se ahorra tiempo
 * 
 * @param data 
 * @return int 
 */
int	ft_end_philo(t_data *data)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WUNTRACED);
	if (WEXITSTATUS(status) == 0)
		ft_kill_all(data, pid);
	return (0);
}

/**
 * @brief Create the fork for each philo
 * 
 * @param data 
 * @return int 
 */
int	ft_create_process(t_data *data, t_philo *philo)
{
	int			count;

	count = 0;
	data->pid = malloc(sizeof(pid_t) * data->num_philos);
	if (!data->pid)
		return (-1);
	while (count < data->num_philos)
	{
		data->pid[count] = 0;
		data->pid[count] = fork();
		if (data->pid[count] > 0)
			count++;
		else if (data->pid[count] == 0)
			return (ft_start_routine(philo, count));
		else
			exit (1);
	}
	ft_delete(philo, data);
	return (0);
}
