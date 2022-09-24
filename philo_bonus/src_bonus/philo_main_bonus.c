/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:05:24 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/22 20:56:27 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo;

	if (!ft_check_argc(argc) || !ft_check_numbers(argv))
		return (-1);
	data.time_start = ft_time();
	if (ft_init(&data, &philo, argv) == -1)
		return (-1);
	ft_create_process(&data, philo);
	ft_delete(&data);
	return (0);
}
