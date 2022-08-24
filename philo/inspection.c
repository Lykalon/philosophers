/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:17:02 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/02 21:58:21 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_eat_time(t_forks *p_fork)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(&p_fork->eat_time);
	p_fork->last_eat = now;
	pthread_mutex_unlock(&p_fork->eat_time);
}

int	check_eats(t_forks *p_fork)
{
	int	eats;

	pthread_mutex_lock(&p_fork->eat_count);
	eats = p_fork->was_eat;
	pthread_mutex_unlock(&p_fork->eat_count);
	return (eats);
}

void	iter_eats(t_forks *p_fork)
{
	pthread_mutex_lock(&p_fork->eat_count);
	p_fork->was_eat = p_fork->was_eat + 1;
	pthread_mutex_unlock(&p_fork->eat_count);
}

int	check_died(t_forks *p_fork)
{
	struct timeval	now;
	long long		a;
	long long		b;

	gettimeofday(&now, 0);
	a = now.tv_sec * 1000000 + now.tv_usec;
	pthread_mutex_lock(&p_fork->eat_time);
	b = p_fork->last_eat.tv_sec * 1000000 + p_fork->last_eat.tv_usec;
	pthread_mutex_unlock(&p_fork->eat_time);
	if ((a - b) >= p_fork->time_die)
	{
		pthread_mutex_lock(p_fork->micro);
		broadcast(DEAD, p_fork, 1);
		set_stop(p_fork);
		pthread_mutex_unlock(p_fork->micro);
		return (1);
	}
	return (0);
}

void	start_inspection(t_forks *forks)
{
	t_forks	*temp;
	int		was_eat;

	temp = forks;
	was_eat = 0;
	while (1)
	{
		if (check_died(temp))
			break ;
		if ((check_eats(temp) >= temp->to_eat) && temp->to_eat)
			++was_eat;
		else
			was_eat = 0;
		temp = temp->next;
		if (was_eat == temp->philo)
			break ;
	}
	pthread_mutex_lock(temp->micro);
	set_stop(forks);
	pthread_mutex_unlock(temp->micro);
}
