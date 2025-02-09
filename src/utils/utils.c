/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:50:29 by karamire          #+#    #+#             */
/*   Updated: 2025/02/09 04:21:03 by karamire         ###   ########.fr       */
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

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while ((*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
}
