/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaissramirez <kaissramirez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:06:25 by karamire          #+#    #+#             */
/*   Updated: 2025/01/18 09:08:24 by kaissramire      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_a_in_b_match(t_list *stack_a, t_list *stack_b)
{
	t_list	*b;
	t_list	*target;
	int		index_match;

	while (stack_a != NULL)
	{
		index_match = INT_MIN;
		b = stack_b;
		while (b != NULL)
		{
			if (b->value < stack_a->value && b->value > index_match)
			{
				index_match = b->value;
				target = b;
			}
			b = b->next;
		}
		stack_a->target = target;
		stack_a = stack_a->next;
	}
}

int	list_size(t_list *stack)
{
	int	i;
	t_list	*s;

	i = 0;
	s = stack;
	while (s != NULL)
	{
		s = s->next;
		i++;
	}
	return (i);
}
int	median_bool(t_list *stack)
{
	int	size;
	size = list_size(stack);
	if (stack->pos >= size/2)
		return(1);
	else
		return(0);
}

void	cost_calculator(t_list *stack_a, t_list *stack_b)
{
	int	a_med;
	int	b_med;

	
}

