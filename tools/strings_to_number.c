/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_to_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:03:10 by pivanovi          #+#    #+#             */
/*   Updated: 2014/11/06 19:03:10 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static int	nb_number(char *str)
{
	int		nb;

	nb = 1;
	str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
		nb *= 10;
		str++;
	}
	return (nb);
}

int			str_to_int(char *str)
{
	int		result;
	int		mul;

	mul = nb_number(str);
	result = 0;
	while (*str >= '0' && *str <= '9' && *str)
	{
		result += (*str - '0') * mul;
		mul /= 10;
		str++;
	}
	return (result);
}
