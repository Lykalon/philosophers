/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:16:07 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/02 16:10:19 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_args(char **argv)
{
	char	**temp;
	char	*str;
	int		i;

	temp = argv;
	i = 1;
	while (temp[i])
	{
		str = argv[i];
		while (*str)
		{
			if (!is_digit(*str))
				return (0);
			str++;
		}
		++i;
	}
	return (1);
}

static int	init_params(int argc, char **argv, t_init *init)
{
	int	status;

	init->to_eat = 0;
	status = check_args(argv);
	if (!status)
		return (0);
	init->philo = ft_atoi(argv[1]);
	init->time_die = ft_atoi(argv[2]) * 1000;
	init->time_eat = ft_atoi(argv[3]) * 1000;
	init->time_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		init->to_eat = ft_atoi(argv[5]);
	if (init->philo == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_forks			*forks;
	t_init			init;
	int				status;
	pthread_mutex_t	micro;

	if (argc == 6 || argc == 5)
	{
		status = init_params(argc, argv, &init);
		if (status)
		{
			pthread_mutex_init(&micro, NULL);
			init.micro = &micro;
			forks = init_forks(init);
			if (!forks)
				return (1);
			start_simulation(init, forks);
			clear_forks(forks);
			pthread_mutex_destroy(&micro);
		}
		else
			print_invalid_args();
	}
	else
		print_usage();
	return (0);
}
