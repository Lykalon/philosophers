/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:14:29 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/09 15:57:41 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(int usec)
{
	struct timeval	start;
	struct timeval	now;
	long long		a;
	long long		b;

	gettimeofday(&start, NULL);
	a = start.tv_sec * 1000000 + start.tv_usec;
	gettimeofday(&now, NULL);
	b = now.tv_sec * 1000000 + now.tv_usec;
	usleep(usec * 9 / 10);
	while (b - a < usec)
	{
		usleep(100);
		gettimeofday(&now, NULL);
		b = now.tv_sec * 1000000 + now.tv_usec;
	}
}
