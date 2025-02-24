/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:06:25 by karamire          #+#    #+#             */
/*   Updated: 2025/02/19 14:05:40 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_size(t_list *stack)
{
	int		i;
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

void	index_init(t_list **stack_a)
{
	t_list	*a;

	a = (*stack_a);
	while (a != NULL)
	{
		a->index = -1;
		a = a->next;
	}
}

void	stack_index(t_list **stack_a)
{
	int		i;
	t_list	*a;
	t_list	*min;

	i = 0;
	index_init(stack_a);
	while (i != list_size(*stack_a))
	{
		a = (*stack_a);
		min = NULL;
		while (a != NULL)
		{
			if ((min == NULL || a->value < min->value) && a->index == -1)
			{
				min = a;
			}
			a = a->next;
		}
		if (min != NULL)
		{
			min->index = i;
			i++;
		}
	}
}

int	chunk_size_calc(int list_size)
{
	int	chunk;

	chunk = 0.000000053 * (list_size * list_size) + 0.03 * list_size + 14.5;
	return (chunk);
}
