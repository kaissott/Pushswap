/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:21:57 by karamire          #+#    #+#             */
/*   Updated: 2025/01/13 11:44:55 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *arg)
{
	int	i;
	int	len;

	i = 0;
	if (arg[i] == '-' && ft_isdigit(arg[i + 1]))
		i++;
	len = ft_strlen(arg);
	while(arg[i] != '\0')
	{
		if(!ft_isdigit(arg[i]))
			return(0);
		i++;
	}
	return(1);
}

int	duplicate_error();
