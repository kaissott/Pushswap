/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:18:33 by karamire          #+#    #+#             */
/*   Updated: 2025/01/15 16:07:00 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list *temp;
	t_list *tempb;

	if (stack_a == NULL)
		return;
	temp = (*stack_a);
	tempb = temp->next;
	(*stack_a) = tempb;
	temp->next = tempb->next;
	tempb->next = temp;
	write(1, "sa", 2);
}

void	sb(t_list **stack_b)
{
	t_list *temp;
	t_list *tempb;

	if (stack_b == NULL)
		return;
	temp = (*stack_b);
	tempb = temp->next;
	(*stack_b) = tempb;
	temp->next = tempb->next;
	tempb->next = temp;
	write(1, "sb", 2);
}
void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
	t_list *tempb;

	if (stack_b == NULL || stack_a == NULL)
		return;
	temp = (*stack_a);
	tempb = temp->next;
	(*stack_a) = tempb;
	temp->next = tempb->next;
	tempb->next = temp;
	temp = NULL;
	tempb = NULL;
	temp = (*stack_b);
	tempb = temp->next;
	(*stack_b) = tempb;
	temp->next = tempb->next;
	tempb->next = temp;
	write(1, "ss", 2);
}
/* const void	pa_pb(t_list *stack_a, t_list *stack_b, int index)
{
	t_list	*temp;

	if (index == 1)
	{
		temp = stack_a;
		ft_lstadd_front(stack_b, &temp);
		stack_a = stack_a->next;
	}
} */
