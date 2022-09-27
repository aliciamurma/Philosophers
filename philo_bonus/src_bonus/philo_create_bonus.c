/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:50:15 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/27 19:58:36 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "../inc_bonus/philo_bonus.h"
#include <sys/wait.h>

/**
 * @brief Delete the semaphores
 * 
 * @param philo 
 */
void	ft_delete_semaphores(t_philo *philo)
{
	sem_close(philo->fork);
	sem_close(philo->print);
	sem_close(philo->eating);
}

/**
 * @brief Make a kill for each pid (= each philo)
 * If any of the kids die, everybody dies
 * 
 * @param data 
 * @param pid 
 * @return int 
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
 * the waitpid function uses the -1 number to check any PID and not only 1
 * (= less time)
 * WEXISTATUS == 0 for death processes
 * WEXISTATUS == 1 for routine completed
 * 
 * @param data 
 */
void	ft_check_deaths(t_data *data)
{
	int		count;
	pid_t	pid;
	int		status;

	count = 0;
	while (count < data->num_philos)
	{
		pid = waitpid(-1, &status, WUNTRACED);
		if (WEXITSTATUS(status) == 0)
			break ;
		if (WEXITSTATUS(status) == 1)
			count++;
	}
	ft_kill_all(data, pid);
}

/**
 * @brief Ceate a fork for each philo
 * The time used to create pthreads <<<< forks, because is
 * a new program and its need to do a copy of everything
 * 
 * @param data 
 * @param philo 
 * @return int 
 */
int	ft_create_process(t_data *data, t_philo *philo)
{
	int	count;


	count = 0;
	data->pid = malloc(sizeof(pid_t) * data->num_philos);
	if (!data->pid)
		return (-1);
	while (count < data->num_philos)
	{
		data->pid[count] = fork();
		if (data->pid[count] > 0)
			count++;
		else if (data->pid[count] == 0)
		{
			ft_start_routine(philo, count);
			break ;
		}
		else
			exit (1);
	}
	ft_check_deaths(data);
	return (0);
}
