/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:41:43 by karamire          #+#    #+#             */
/*   Updated: 2025/01/16 17:14:22 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack_two(t_list **stack_a)
{
	if (((*stack_a)->value) > ((*stack_a)->next->value))
		ra(stack_a, 1);
	/* print_stack(*stack_a); */
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

int	sort_stack(int ac, t_list **stack_a, t_list **stack_b)
{
	if (ac == 3)
		sort_stack_two(stack_a);
	else if (ac == 4)
		sort_stack_three(stack_a);
	else if (ac == 6)
		sort_stack_five(stack_a, stack_b);
	/* 		else if (ac > 6)
				sort_stack_no_limit(stack_a); */
	return (0);
}
