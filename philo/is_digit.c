/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:18:41 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/27 22:18:41 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_digit(int ch)
{
	if ((ch >= 48) && (ch <= 57))
		return (ch);
	else
		return (0);
}