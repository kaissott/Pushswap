/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:21:41 by karamire          #+#    #+#             */
/*   Updated: 2025/02/19 14:00:45 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **stack_a, int p)
{
	t_list	*last;
	t_list	*temp;

	last = (*stack_a);
	temp = NULL;
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = (*stack_a);
	(*stack_a) = last;
	if (p == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int p)
{
	t_list	*last;
	t_list	*temp;

	last = (*stack_b);
	temp = NULL;
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = (*stack_b);
	(*stack_b) = last;
	if (p == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int i)
{
	if (stack_a != NULL)
		rra(stack_a, 0);
	if (stack_b != NULL)
		rrb(stack_b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}
