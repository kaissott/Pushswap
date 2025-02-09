/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:36:01 by karamire          #+#    #+#             */
/*   Updated: 2025/02/09 06:11:13 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **stack_a, int p)
{
	t_list	*last;
	t_list	*temp;

	last = ft_lstlast(*stack_a);
	temp = (*stack_a);
	(*stack_a) = temp->next;
	last->next = temp;
	temp->next = NULL;
	if (p == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int p)
{
	t_list	*last;
	t_list	*temp;

	last = ft_lstlast(*stack_b);
	temp = (*stack_b);
	(*stack_b) = temp->next;
	last->next = temp;
	temp->next = NULL;
	if (p == 1)
		write(1, "rb\n", 3);
}
void	rr(t_list **stack_a, t_list **stack_b, int i)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
