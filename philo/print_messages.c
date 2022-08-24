/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:55:18 by lykalon           #+#    #+#             */
/*   Updated: 2022/07/04 20:55:18 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_usage(void)
{
	printf("USAGE arguments: \n");
	printf("1 - number of philosophers\n");
	printf("2 - time to die\n");
	printf("3 - time to eat\n");
	printf("4 - time to sleep\n");
	printf("5 (optional) - number of times each philosopher must eat ");
	printf("(0 - makes default start)\n");
}

void	print_invalid_args(void)
{
	printf("Invalid args...\n");
}
