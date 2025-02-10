/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:15:47 by karamire          #+#    #+#             */
/*   Updated: 2025/02/04 14:08:05 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*s;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > 4294967295 / size)
		return (NULL);
	s = malloc(size * nmemb);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return ((void *)s);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	newstr = ft_calloc(len + 1, sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		newstr[i] = s[start];
		i++;
		start++;
	}
	return (newstr);
}

/* int	main(void)
{
	char	str[] = "123456789";

	printf("%s\n", ft_substr(str, 1, 20));
} */
