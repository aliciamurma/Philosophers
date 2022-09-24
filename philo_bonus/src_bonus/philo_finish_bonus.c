/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finish_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:28:48 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/22 11:32:24 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

/**
 * @brief Check if the routine is completed acording with the number
 * of times that each philo must eat
 * 
 * @param data 
 * @return int 
 */
// int	ft_routine_completed(t_data *data)
// {
// 	int		count;
// 	int		finish;

// 	count = 0;
// 	finish = 0;
// 	if (data->num_times_eat == 0)
// 		return (1);
// 	while (count < data->num_philos)
// 	{
// 		if (data->philo[count].need_eat >= data->num_times_eat)
// 			finish++;
// 		else
// 			break ;
// 		count++;
// 	}
// 	if (finish >= data->num_philos)
// 	{
// 		// data->death = 1;
// 		return (0);
// 	}
// 	return (1);
// }

/**
 * @brief Check if the philos die
 * 
 * @param data 
 * @return int 
 */
// int	ft_die(t_data *data)
// {
// 	int	count;

// 	count = 0;
// 	while (count < data->num_philos)
// 	{
// 		if (data->time_die < (long long int)((ft_time() - data->time_start)
// 			- data->philo[count].last_eat))
// 		{
// 			ft_print("die", data->philo);
// 			// data->philo->death = 1;
// 			return (0);
// 		}
// 		count++;
// 	}
// 	return (1);
// }
