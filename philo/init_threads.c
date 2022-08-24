/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:12:40 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/30 21:19:43 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_threads	*thread_new(int index)
{
	t_threads	*new;

	new = malloc(sizeof(t_threads));
	if (!new)
		return (NULL);
	new->index = index;
	new->next = NULL;
	return (new);
}

static t_threads	*thread_push_back(t_threads *first, t_threads *new)
{
	t_threads	*last;

	if (!first)
		return (new);
	last = first;
	while (last->next)
		last = last->next;
	last->next = new;
	return (first);
}

t_threads	*init_threads(int philo)
{
	t_threads	*new;
	t_threads	*first;
	int			i;

	i = 1;
	first = NULL;
	while (i <= philo)
	{
		new = thread_new(i);
		if (!new)
		{
			clear_threads(first);
			return (NULL);
		}
		first = thread_push_back(first, new);
		++i;
	}
	return (first);
}
