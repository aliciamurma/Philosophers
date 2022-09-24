/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:50:08 by amurcia-          #+#    #+#             */
/*   Updated: 2022/09/24 21:46:30 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <semaphore.h>
# include <signal.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pthread.h>

//STATUS DE SALIDA PORQUE HA SALIDO BIEN - STATUS 2
//STATUS DE SALIDA PORQUE HAN MUERTO - 1
typedef struct s_philo
{
	long long int	time_die;
	long long int	time_eat;
	long long int	time_sleep;
	long long int	num_times_eat;
	long long int	time_actual;
	long long int	time_start;
	int				name;
	int				need_eat;
	int				status;
	int				id_philo;
	int				num_philos;
	long long int	last_eat;
	sem_t			*fork;
	sem_t			*print;
	sem_t			*eating;
	struct timeval	time_val;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	long long int	time_die;
	long long int	time_eat;
	long long int	time_sleep;
	long long int	num_times_eat;
	long long int	time_actual;
	long long int	time_start;
	sem_t			*print;
	pid_t			*pid;
}	t_data;

// CHECK
bool			ft_check_argc(int argc);
bool			ft_check_numbers(char **argv);

// INIT
int				ft_init(t_data *data, t_philo *philo, char **argv);

// UTILS
bool			ft_isdigit(int c);
int				ft_atoi(const char *str);
long long int	ft_time(void);
void			ft_usleep(int nbr);
void			ft_handle_signal(int signal);

// CREATE
int				ft_create_process(t_data *data, t_philo *philo);
int				ft_end_philo(t_data *data);
int				ft_kill_all(t_data *data, pid_t pid);

// PRINT
void			ft_print(char *str, t_philo *philo);

// ROUTINE
int				ft_start_routine(t_philo *philo, int id);
void			*ft_routine(void *void_philo);

// FINISH
int				ft_routine_completed(t_philo *philo);
int				ft_die(t_philo *philo);

// DELETE
void			ft_delete(t_philo *philo, t_data *data);
void			ft_delete_semaphores(t_philo *philo);

#endif