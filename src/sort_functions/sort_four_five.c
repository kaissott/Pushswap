/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:06:12 by karamire          #+#    #+#             */
/*   Updated: 2025/02/19 14:01:06 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack_five(t_list **stack_a, t_list **stack_b, int i)
{
	search_and_push_min(stack_a, stack_b);
	if (i == 5)
		search_and_push_min(stack_a, stack_b);
	sort_stack_three(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}

void	search_and_push_min_two(t_list **stack_a, t_list **stack_b, int pos,
		int i)
{
	if (pos < 3)
	{
		i = 0;
		while (i < pos)
		{
			ra(stack_a, 1);
			i++;
		}
	}
	else
	{
		while (i > pos)
		{
			rra(stack_a, 1);
			i--;
		}
	}
	pb(stack_a, stack_b, 1);
}

void	search_and_push_min(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		i;
	int		j;
	t_list	*temp;

	i = 0;
	j = 0;
	temp = (*stack_a);
	min = temp->value;
	while (temp != NULL)
	{
		if (temp->value < min)
		{
			min = temp->value;
			j = i;
		}
		temp = temp->next;
		i++;
	}
	if (i == 0)
		pb(stack_a, stack_b, 1);
	else
		search_and_push_min_two(stack_a, stack_b, j, i);
}
