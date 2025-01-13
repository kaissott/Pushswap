/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:34:07 by kaissramire       #+#    #+#             */
/*   Updated: 2024/12/19 11:50:27 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

static char	*resetline(char *saveline)
{
	size_t	i;

	i = 0;
	if (saveline == NULL)
		return (NULL);
	while (saveline[i] != '\n' && saveline[i])
		i++;
	if (saveline[i] == '\n')
		i++;
	if (saveline[i] == '\0')
		return (free(saveline), NULL);
	ft_memcpy(saveline, saveline + i, ft_strlen(saveline) - i + 1);
	return (saveline);
}

static char	*setline(char *saveline)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!saveline)
		return (NULL);
	while (saveline[i] != '\n' && saveline[i])
		i++;
	if (saveline[i] != '\n')
		i--;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (saveline[i] != '\n' && saveline[i])
	{
		str[i] = saveline[i];
		i++;
	}
	if (saveline[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*readline(int fd, char *saveline)
{
	char	*buffer;
	ssize_t	i;

	i = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(saveline), NULL);
	while (!ft_strchr(saveline, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer), free(saveline), saveline = NULL, NULL);
		if (i == 0)
		{
			if (saveline)
				return (free(buffer), saveline);
			return (free(buffer), free(saveline), NULL);
		}
		buffer[i] = '\0';
		saveline = ft_strjoin(saveline, buffer);
		if (!saveline)
			return (free(buffer), NULL);
	}
	return (free(buffer), saveline);
}

char	*get_next_line(int fd)
{
	static char	*saveline[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saveline[fd] = readline(fd, saveline[fd]);
	if (!saveline[fd])
		return (NULL);
	line = setline(saveline[fd]);
	if (!line)
	{
		free(saveline[fd]);
		saveline[fd] = NULL;
		return (NULL);
	}
	saveline[fd] = resetline(saveline[fd]);
	return (line);
}

/* int    main(void)
{
	int        fd;
	char    *str;

	fd = open("multiple_nl.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Erreur d'ouverture\n", 19);
		return (1);
	}
	str = get_next_line(fd);
	printf("line: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("line: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("line: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("line: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("line: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("line: %s", str);
	free(str);

	close(fd);
	return (0);
} */
