/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:21:57 by karamire          #+#    #+#             */
/*   Updated: 2025/02/05 18:54:38 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	syntax_error(char *av)
{
	int	i;
	int	len;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && ft_isdigit(av[i + 1]))
		i++;
	len = ft_strlen(av);
	while (av[i] != '\0')
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	duplicate_error(t_list *stack_a, int nb)
{
	t_list	*check;

	if (stack_a == NULL)
		return (0);
	check = stack_a;
	while (check != NULL)
	{
		if (check->value == nb)
			return (-1);
		check = check->next;
	}
	return (1);
}


void	check_stack(t_list **stack_a, int ac, char **av)
{
	int		i;
	int		nbr;
	int		j;
	char	**temp;

	i = 1;
	while (i++ < ac)
	{
		j = 0;
		temp = ft_split(av[i], 32);
		while (temp[j++] != NULL)
		{
			if (!syntax_error(temp[j]))
			{
				write(1, "Error\n", 6);
				return ;
			}
			nbr = ft_atoi(temp[j]);
			if (duplicate_error(*stack_a, nbr) == -1)
			{
				write(1, "Error\n", 6);
				return ;
			}
			put_in_stack_a(stack_a, nbr);
			free(temp[j]);
		}
		free(temp);
	}
}
