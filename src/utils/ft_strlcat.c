/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:19:25 by karamire          #+#    #+#             */
/*   Updated: 2025/02/04 15:12:02 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
