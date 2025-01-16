/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:10:46 by karamire          #+#    #+#             */
/*   Updated: 2025/01/16 17:15:22 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_b) == NULL)
		return ;
	temp = (*stack_b);
	(*stack_b) = temp->next;
	temp->next = (*stack_a);
	(*stack_a) = temp;
	write(1, "pa\n", 3);
}
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_a) == NULL)
		return ;
	temp = (*stack_a);
	(*stack_a) = temp->next;
	temp->next = (*stack_b);
	(*stack_b) = temp;
	write(1, "pb\n", 3);
}
