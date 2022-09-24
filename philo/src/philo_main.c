/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:44:52 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/20 17:00:35 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!ft_check_argc(argc) || !ft_check_numbers(argv))
		return (-1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (ft_init(data, argv) == -1)
		return (-1);
	data->time_start = ft_time();
	ft_create_pthread(data);
	ft_delete(data);
	return (0);
}
