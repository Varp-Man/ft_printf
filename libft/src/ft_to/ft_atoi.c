/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkorolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:13:06 by bkorolov          #+#    #+#             */
/*   Updated: 2022/10/20 17:15:13 by bkorolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{	
	int				k;
	int				sign;
	long long int	ret;

	sign = 1;
	ret = 0;
	k = 0;
	while (ft_isspace(nptr[k]))
		k++;
	if (nptr[k] == '+' || nptr[k] == '-')
	{
		if (nptr[k] == '-')
			sign = sign * (-1);
		k++;
	}
	while (nptr[k] >= '0' && nptr[k] <= '9')
	{
		ret = ret * 10 + nptr[k] - '0';
		if (sign * ret > 2147483647)
			return (-1);
		else if (ret * sign < -2147483648)
			return (0);
		k++;
	}
	return (sign * ret);
}
