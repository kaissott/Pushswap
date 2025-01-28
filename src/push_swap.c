/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:33:22 by karamire          #+#    #+#             */
/*   Updated: 2025/01/28 18:19:01 by karamire         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_stack(&stack_a, ac, av);
	sort_stack(ac, &stack_a, &stack_b);
	free_stack(&stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
// https://42-cursus.gitbook.io/guide/rank-02/push_swap/building-the-thing
