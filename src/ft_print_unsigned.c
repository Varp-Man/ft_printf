/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkorolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:29:18 by bkorolov          #+#    #+#             */
/*   Updated: 2022/11/22 14:29:21 by bkorolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"
#include <stdlib.h>

int	ft_num_len(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_str_num(char *str, int n, int len)
{
	int	mod;
	int	neg;

	neg = 1;
	if (n < 0)
		neg = -1;
	str[len--] = '\0';
	while (len > 1)
	{
		mod = (n % 10) * neg;
		str[len--] = mod + '0';
		n /= 10;
	}
	if (neg == 1)
	{
		str[len] = (n % 10) + '0';
		str[0] = (n / 10) + '0';
	}
	else if (neg == -1)
	{
		str[len] = (n * -1) + '0';
		str[0] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	if (n <= 0)
		len++;
	num = (char *)malloc((len + 1) * sizeof(char));
	if (!num)
		return (0);
	if (n >= 0 && n < 10)
	{
		num[0] = n + '0';
		num[1] = '\0';
	}
	else
		num = ft_str_num(num, n, len);
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_itoa(n);
		print_length += ft_printstr(num);
		free(num);
	}
	return (print_length);
}
