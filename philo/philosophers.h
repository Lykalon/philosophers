/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:52:17 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/02 21:51:33 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

# define FORK "%lld %d has taken a fork\n"
# define EAT "%lld %d is eating\n"
# define SLEEP "%lld %d is sleeping\n"
# define THINK "%lld %d is thinking\n"
# define DEAD "%lld %d died\n"

typedef struct s_threads
{
	int					index;
	pthread_t			thread;
	struct s_threads	*next;
}				t_threads;

typedef struct s_forks
{
	int				index;
	struct s_forks	*next;
	int				philo;
	int				was_eat;
	struct timeval	start;
	struct timeval	last_eat;
	int				to_eat;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				stop;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_time;
	pthread_mutex_t	eat_count;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	*micro;
}				t_forks;

typedef struct s_init
{
	int				philo;
	int				to_eat;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	pthread_mutex_t	*micro;
}				t_init;

void		print_usage(void);
void		print_invalid_args(void);
int			is_digit(int ch);
int			ft_atoi(const char *str);
t_forks		*init_forks(t_init init);
void		start_simulation(t_init init, t_forks *forks);
t_threads	*init_threads(int philo);
void		clear_forks(t_forks *forks);
void		clear_threads(t_threads *threads);
void		stop_threads(t_threads *threads, int philo);
void		broadcast(const char *type, t_forks *p_fork, int dead);
void		set_stop(t_forks *forks);
int			check_stop(t_forks *p_fork);
void		clear_philo(t_forks *p_fork);
void		iter_eats(t_forks *p_fork);
void		start_inspection(t_forks *forks);
void		ft_usleep(int usec);
void		set_eat_time(t_forks *p_fork);

#endif
