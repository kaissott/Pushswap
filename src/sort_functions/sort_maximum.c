/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_maximum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 06:39:52 by kaissramire       #+#    #+#             */
/*   Updated: 2025/01/28 21:11:18 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_bigger(t_list *stack_b)
{
	int		i;
	t_list	*b;

	i = 0;
	b = (stack_b);
	while (b != NULL)
	{
		if (b->index > i)
			i = b->index;
		b = b->next;
	}
	return (i);
}
void	first_push(t_list **stack_a, t_list **stack_b, int chunk)
{
	int		i;

	i = 0;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index < chunk)
		{
			pb(stack_a, stack_b);
			break ;
		}
		ra(stack_a, 1);
	}
}

void	push_b_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	int		median;
	int		size;
	int		i;
	int		j;

	while (list_size(*stack_b) > 0)
	{
		size = list_size(*stack_b);
		median = (size / 2);
		i = search_bigger(*stack_b);
		b = (*stack_b);
		j = 0;
		while (b != NULL)
		{
			if (b->index == i)
				break ;
			j++;
			b = b->next;
		}
		if (j <= median)
		{
			while (j-- > 0)
				rb(stack_b, 1);
		}
		else
		{
			while (j++ < size)
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b);
	}
}

void	sort_stack_max(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	b;

	stack_index(stack_a);
	i = list_size(*stack_a);
	j = chunk_size_calc(list_size(*stack_a));
	first_push(stack_a, stack_b, j);
	while (list_size(*stack_a) > 3)
	{
		b = list_size(*stack_b);
		if ((*stack_a)->index > (b + j) || (*stack_a)->index >= (i - 3))
			ra(stack_a, 1);
		else
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->index > b && (*stack_b)->index <= (j + b))
				rb(stack_b, 1);
		}
	}
	sort_stack_three(stack_a);
	push_b_to_a(stack_a, stack_b);
}
