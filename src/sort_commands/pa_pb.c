/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:10:46 by karamire          #+#    #+#             */
/*   Updated: 2025/01/16 16:04:12 by karamire         ###   ########.fr       */
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
}
