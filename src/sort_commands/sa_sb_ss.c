/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:18:33 by karamire          #+#    #+#             */
/*   Updated: 2025/02/19 14:00:51 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a, int p)
{
	t_list	*temp;
	t_list	*tempb;

	if (stack_a == NULL)
		return ;
	temp = (*stack_a);
	tempb = temp->next;
	(*stack_a) = tempb;
	temp->next = tempb->next;
	tempb->next = temp;
	if (p == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int p)
{
	t_list	*temp;
	t_list	*tempb;

	if (stack_b == NULL)
		return ;
	temp = (*stack_b);
	tempb = temp->next;
	(*stack_b) = tempb;
	temp->next = tempb->next;
	tempb->next = temp;
	if (p == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int i)
{
	sa(stack_a, 0);
	sa(stack_b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}
