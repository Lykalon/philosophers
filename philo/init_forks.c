/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:07:58 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/02 16:10:02 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_forks	*fork_new(int index, t_init init)
{
	t_forks	*new;

	new = malloc(sizeof(t_forks));
	if (!new)
		return (NULL);
	new->index = index;
	new->next = NULL;
	new->philo = init.philo;
	new->was_eat = 0;
	new->to_eat = init.to_eat;
	new->time_die = init.time_die;
	new->time_eat = init.time_eat;
	new->time_sleep = init.time_sleep;
	new->stop = 0;
	pthread_mutex_init(&new->mutex, NULL);
	pthread_mutex_init(&new->eat_time, NULL);
	pthread_mutex_init(&new->eat_count, NULL);
	pthread_mutex_init(&new->mutex_stop, NULL);
	new->micro = init.micro;
	return (new);
}

static t_forks	*fork_push_back(t_forks *first, t_forks *new)
{
	t_forks	*last;

	if (!first)
	{
		new->next = new;
		return (new);
	}
	last = first;
	while (last->next != first)
		last = last->next;
	last->next = new;
	new->next = first;
	return (first);
}

t_forks	*init_forks(t_init init)
{
	t_forks	*new;
	t_forks	*first;
	int		i;

	i = 1;
	first = NULL;
	while (i <= init.philo)
	{
		new = fork_new(i, init);
		if (!new)
		{
			clear_forks(first);
			return (NULL);
		}
		first = fork_push_back(first, new);
		++i;
	}
	return (first);
}
