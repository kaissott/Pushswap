/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:21:57 by karamire          #+#    #+#             */
/*   Updated: 2025/02/19 14:05:56 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	return_error(t_list **stack_a, char **temp)
{
	int	i;

	i = 0;
	if (temp)
	{
		while (temp[i] != NULL)
			free(temp[i++]);
		free(temp);
	}
	ft_lstclear(stack_a, free);
	write(2, "Error\n", 6);
	return (0);
}

int	syntax_error(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && ft_isdigit(av[i + 1]))
		i++;
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

	check = stack_a;
	while (check != NULL)
	{
		if (check->value == nb)
			return (0);
		check = check->next;
	}
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_stack(t_list **stack_a, int ac, char **av, int *e)
{
	int		i;
	int		j;
	int		nbr;
	char	**temp;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		temp = ft_split(av[i], 32);
		if (temp == NULL)
			return (return_error(stack_a, temp));
		while (temp[j] != NULL)
		{
			nbr = ft_atoi(temp[j], e);
			if (!syntax_error(temp[j]) || !duplicate_error(*stack_a, nbr)
				|| *e == -1)
				return (return_error(stack_a, temp));
			if (!put_in_stack_a(stack_a, nbr))
				return (return_error(stack_a, temp));
			j++;
		}
		free_tab(temp);
	}
	return (1);
}
