/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:02:22 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/20 11:24:21 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

/**
 * @brief Look for number of arguments
 * 
 * @param argc 
 * @return true 
 * @return false 
 */
bool	ft_check_argc(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error\nNúmero de parámetros incorrecto\n");
		return (false);
	}
	return (true);
}

/**
 * @brief Check if the passed arguments are numbers
 * 
 * @param argv 
 * @return true 
 * @return false 
 */
bool	ft_check_numbers(char **argv)
{
	int	count;
	int	count_n;

	count = 1;
	count_n = 0;
	if (argv[1] == 0)
	{
		printf("Error\nThere are no philosophers");
		return (false);
	}
	while (argv[count])
	{
		count_n = 0;
		while (argv[count][count_n])
		{
			if (!ft_isdigit(argv[count][count_n]))
			{
				printf("Error\nGive me numbers\n");
				return (false);
			}
				count_n++;
		}
		count++;
	}
	return (true);
}
