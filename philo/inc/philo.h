/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:48:00 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/20 11:43:29 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/time.h>
# include <pthread.h>
# include "colors.h"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				name;
	int				right_fork;
	int				left_fork;
	long long int	last_eat;
	int				need_eat;
	long long int	time_start;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	long long int	time_die;
	long long int	time_eat;
	long long int	time_sleep;
	long long int	num_times_eat;
	int				death;
	long long int	time_actual;
	long long int	time_start;
	t_philo			*philo;
	pthread_mutex_t	m_death;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_print;
}	t_data;

// CHECK
bool			ft_check_argc(int argc);
bool			ft_check_numbers(char **argv);

// UTILS
bool			ft_isdigit(int c);
int				ft_atoi(const char *str);
long long int	ft_time(void);
void			ft_usleep(int nbr);

// INIT
int				ft_init(t_data *data, char **argv);
int				ft_init_data(t_data *data, char **argv);
int				ft_init_mutex(t_data *data);
int				ft_init_philos(t_data *data);

// PRINT
void			ft_print_die(t_philo *philo);
void			ft_print_sleep(t_philo *philo);
void			ft_print_fork(t_philo *philo);
void			ft_print_eat(t_philo *philo);
void			ft_print_think(t_philo *philo);

// CREATE
int				ft_create_pthread(t_data *data);

// ROUTINE
void			*ft_start_routine(void *cosa);
int				ft_die(t_data *data);

// FINISH
int				ft_routine_completed(t_data *data);
int				ft_die(t_data *data);

// DELETE
void			ft_delete(t_data *data);

#endif
