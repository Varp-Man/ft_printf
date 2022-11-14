/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkorolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:30:14 by bkorolov          #+#    #+#             */
/*   Updated: 2022/10/27 15:05:31 by bkorolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*cpy;
	size_t			strsize;

	if (!s)
		return (NULL);
	strsize = ft_strlen(s);
	if (start >= strsize)
		start = strsize;
	if (len > strsize - start)
		len = strsize - start;
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, &s[start], len + 1);
	return (cpy);
}
