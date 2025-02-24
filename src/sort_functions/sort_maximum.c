/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_maximum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 06:39:52 by kaissramire       #+#    #+#             */
/*   Updated: 2025/02/19 16:57:55 by karamire         ###   ########.fr       */
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

void	first_push(t_list **stack_a, t_list **stack_b, int chunk, int i)
{
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index < chunk && (*stack_a)->index < (i - 3))
		{
			pb(stack_a, stack_b, 1);
			break ;
		}
		ra(stack_a, 1);
	}
}

void	push_b_to_a(t_list **stack_a, t_list **stack_b, int i, int j)
{
	t_list	*b;
	int		size;

	while (list_size(*stack_b) > 0)
	{
		size = list_size(*stack_b);
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
		if (j <= (size / 2))
			while (j-- > 0)
				rb(stack_b, 1);
		else
			while (j++ < size)
				rrb(stack_b, 1);
		pa(stack_a, stack_b, 1);
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
	first_push(stack_a, stack_b, j, i);
	while (list_size(*stack_a) > 3)
	{
		b = list_size(*stack_b);
		if ((*stack_a)->index > (b + j) || (*stack_a)->index >= (i - 3))
			ra(stack_a, 1);
		else
		{
			pb(stack_a, stack_b, 1);
			if ((*stack_b)->index > b && (*stack_b)->index <= (j + b))
				rb(stack_b, 1);
		}
	}
	sort_stack_three(stack_a);
	push_b_to_a(stack_a, stack_b, 0, 0);
}
int	check_is_sorted(t_list **stack_a)
{
	t_list	*temp;

	temp = (*stack_a);
	while (temp->next != NULL)
	{
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			break ;
	}
	if (temp->next == NULL)
		return (1);
	else
		return (0);
}
