/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:57:53 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/02 22:13:57 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clear_forks(t_forks *forks)
{
	t_forks	*temp;
	t_forks	*next;

	temp = forks;
	if (!forks)
		return ;
	if (forks->next == forks)
	{
		free (temp);
		return ;
	}
	while (temp->next != forks)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}

void	clear_threads(t_threads *threads)
{
	t_threads	*temp;
	t_threads	*next;

	temp = threads;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}

void	stop_threads(t_threads *threads, int philo)
{
	t_threads	*temp;

	temp = threads;
	if (philo == 1)
	{
		pthread_detach(temp->thread);
		return ;
	}
	while (temp)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
	}
}

void	set_stop(t_forks *forks)
{
	t_forks	*temp;

	temp = forks;
	pthread_mutex_lock(&temp->mutex_stop);
	temp->stop = 1;
	pthread_mutex_unlock(&temp->mutex_stop);
	temp = temp->next;
	while (temp != forks)
	{
		pthread_mutex_lock(&temp->mutex_stop);
		temp->stop = 1;
		pthread_mutex_unlock(&temp->mutex_stop);
		temp = temp->next;
	}
}

void	clear_philo(t_forks *p_fork)
{
	pthread_mutex_destroy(&p_fork->mutex_stop);
	pthread_mutex_destroy(&p_fork->eat_count);
	pthread_mutex_destroy(&p_fork->eat_time);
	pthread_mutex_destroy(&p_fork->mutex);
	p_fork->micro = NULL;
}
