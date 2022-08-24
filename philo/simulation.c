/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:50:13 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/10 16:30:50 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*living(void *data)
{
	t_forks			*p_fork;
	int				stop;

	p_fork = data;
	stop = check_stop(p_fork);
	while (!stop)
	{
		pthread_mutex_lock(&p_fork->mutex);
		broadcast(FORK, p_fork, 0);
		pthread_mutex_lock(&p_fork->next->mutex);
		broadcast(FORK, p_fork, 0);
		set_eat_time(p_fork);
		broadcast(EAT, p_fork, 0);
		ft_usleep(p_fork->time_eat);
		pthread_mutex_unlock(&p_fork->next->mutex);
		pthread_mutex_unlock(&p_fork->mutex);
		iter_eats(p_fork);
		broadcast(SLEEP, p_fork, 0);
		ft_usleep(p_fork->time_sleep);
		broadcast(THINK, p_fork, 0);
		stop = check_stop(p_fork);
	}
	clear_philo(p_fork);
	return (0);
}

void	init_even(t_forks *forks, t_threads *threads)
{
	t_threads		*temp;
	t_forks			*tmp_forks;
	struct timeval	time;

	temp = threads;
	tmp_forks = forks;
	while (temp)
	{
		if (temp->index % 2 == 0)
		{
			gettimeofday(&time, 0);
			tmp_forks->start = time;
			tmp_forks->last_eat = time;
			pthread_create(&temp->thread, 0, living, tmp_forks);
		}
		temp = temp->next;
		tmp_forks = tmp_forks->next;
	}
}

void	init_odd(t_forks *forks, t_threads *threads)
{
	t_threads		*temp;
	t_forks			*tmp_forks;
	struct timeval	time;

	temp = threads;
	tmp_forks = forks;
	while (temp)
	{
		if (temp->index % 2 == 1)
		{
			gettimeofday(&time, 0);
			tmp_forks->start = time;
			tmp_forks->last_eat = time;
			pthread_create(&temp->thread, 0, living, tmp_forks);
		}
		temp = temp->next;
		tmp_forks = tmp_forks->next;
	}
}

void	philo_alive(t_forks *forks, t_threads *threads)
{
	init_even(forks, threads);
	ft_usleep(50);
	init_odd(forks, threads);
}

void	start_simulation(t_init init, t_forks *forks)
{
	t_threads		*threads;

	threads = init_threads(init.philo);
	if (!threads)
		return ;
	philo_alive(forks, threads);
	start_inspection(forks);
	stop_threads(threads, forks->philo);
	clear_threads(threads);
}
