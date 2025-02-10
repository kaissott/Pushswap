/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:50:29 by karamire          #+#    #+#             */
/*   Updated: 2025/02/10 10:57:57 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static int	ft_intchecker(long result, long sign, int i, char *str)
{
	if (result > (LONG_MAX - ((str[i] - 48)) / 10))
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	result = result + (str[i] - 48);
	if (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		result = result * 10;
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = ft_intchecker(result, sign, i, (char *)str);
		i++;
	}
	return (result * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcat(char *dst, const char *src)
{
	size_t	s;
	size_t	d;

	d = ft_strlen(dst);
	s = 0;
	while (src[s] != '\0')
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = ' ';
	dst[d + 1] = '\0';
	return (dst);
}
