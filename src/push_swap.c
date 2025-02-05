/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:33:22 by karamire          #+#    #+#             */
/*   Updated: 2025/02/04 15:30:56 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_in_stack_a(t_list **stack_a, int nbr)
{
	t_list	*newelement;

	newelement = malloc(sizeof(t_list));
	if (newelement == NULL)
		return ;
	newelement->value = nbr;
	ft_lstadd_back(stack_a, newelement);
}

char	**create_tab(int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	while (i < ac)
	{
		str = ft_strcat(str, av[i]);
		i++;
	}
	return (ft_split(str, 32));
}
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	check_stack(&stack_a, ac, av);
	sort_stack(list_size(stack_a), &stack_a, &stack_b);
	free_stack(&stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
// https://42-cursus.gitbook.io/guide/rank-02/push_swap/building-the-thing
