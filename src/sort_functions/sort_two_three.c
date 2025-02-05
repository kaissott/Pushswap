/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:41:43 by karamire          #+#    #+#             */
/*   Updated: 2025/02/04 15:37:32 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack_two(t_list **stack_a)
{
	if (((*stack_a)->value) > ((*stack_a)->next->value))
		ra(stack_a, 1);
}

void	sort_stack_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first < second && second > third && first < third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if ((first > second && second < third && first < third))
		sa(stack_a, 1);
	else if (first > second && first > third && second < third)
		ra(stack_a, 1);
	else if (first < second && first > third)
		rra(stack_a, 1);
	else if (first > second && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
}

int	sort_stack(int size, t_list **stack_a, t_list **stack_b)
{
	if (size == 2)
		sort_stack_two(stack_a);
	else if (size == 3)
		sort_stack_three(stack_a);
	else if (size == 5)
		sort_stack_five(stack_a, stack_b);
	else if (size > 5)
		sort_stack_max(stack_a, stack_b);
	return (0);
}
