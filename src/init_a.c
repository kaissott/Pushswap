/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaissramirez <kaissramirez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:45:08 by karamire          #+#    #+#             */
/*   Updated: 2025/01/18 08:04:12 by kaissramire      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_in_stack_a(t_list **stack_a, int nbr, int i)
{
	t_list	*newelement;
	t_list	*last;

	newelement = malloc(sizeof(t_list));
	if (newelement == NULL)
		return ;
	newelement->value = nbr;
	ft_lstadd_back(stack_a, newelement);
}
void	reset_pos(t_list **stack_a)
{
	int	pos;
	t_list	*current;

	current = (*stack_a);
	pos = 0;
	while (current != NULL)
	{
		current->pos = pos;
		pos++;
		current = current->next;
	}
}

/* void	put_in_stack_b(t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	c = malloc(sizeof(t_list));
	a->value = 7;
	b->value = 8;
	c->value = 9;
	if (a == NULL)
		return ;
	a->next = *stack_b;
	*stack_b = a;
	b->next = *stack_b;
	*stack_b = b;
	c->next = *stack_b;
	*stack_b = c;
} */
