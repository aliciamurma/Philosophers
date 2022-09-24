/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:45:42 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/20 17:00:48 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Check if the given int is a digit
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

/**
 * @brief Conversion from char * to int
 * 
 * @param str 
 * @return int 
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	while ((unsigned char)str[i] == ' ' || (unsigned char)str[i] == '\t'
		|| (unsigned char)str[i] == '\n' || (unsigned char)str[i] == '\f'
		|| (unsigned char)str[i] == '\r' || (unsigned char)str[i] == '\v')
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

/**
 * @brief Asignamos el tiempo del sistema expresada en microsegundos
 * 
 * @return long long int 
 */
long long int	ft_time(void)
{
	struct timeval	time;
	long long int	actual;

	gettimeofday(&time, NULL);
	actual = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (actual);
}

/**
 * @brief Creamos nuestra propia función usleep
 * La funció usleep no funciona correctamente para valores altos
 * Necesitamos el tiempo del sistema, 0 es incorrecto, se resetearía
 * A medida que pasamos por el bucle, el tiempo se tiene que actualizar
 * 
 */
void	ft_usleep(int nbr)
{
	long long int	count;

	count = ft_time();
	while (nbr > ft_time() - count)
	{
		usleep(nbr / 2);
	}
}
