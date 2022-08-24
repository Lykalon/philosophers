/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_micro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:17:25 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/02 22:01:39 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_stop(t_forks *p_fork)
{
	int	stop;

	pthread_mutex_lock(&p_fork->mutex_stop);
	stop = p_fork->stop;
	pthread_mutex_unlock(&p_fork->mutex_stop);
	return (stop);
}

void	broadcast(const char *type, t_forks *p_fork, int dead)
{
	struct timeval	now;
	long long		a;
	long long		b;
	int				stop;

	if (!dead)
	{
		pthread_mutex_lock(p_fork->micro);
		stop = check_stop(p_fork);
		if (!stop)
		{
			gettimeofday(&now, 0);
			a = now.tv_sec * 1000 + now.tv_usec / 1000;
			b = p_fork->start.tv_sec * 1000 + p_fork->start.tv_usec / 1000;
			printf(type, a - b, p_fork->index);
		}
		pthread_mutex_unlock(p_fork->micro);
	}
	else
	{
		gettimeofday(&now, 0);
		a = now.tv_sec * 1000 + now.tv_usec / 1000;
		b = p_fork->start.tv_sec * 1000 + p_fork->start.tv_usec / 1000;
		printf(type, a - b, p_fork->index);
	}
}
