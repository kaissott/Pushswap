/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 04:21:34 by karamire          #+#    #+#             */
/*   Updated: 2025/02/19 14:22:16 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	put_in_stack_a(t_list **stack_a, int nbr)
{
	t_list	*newelement;

	newelement = malloc(sizeof(t_list));
	if (newelement == NULL)
		return (0);
	newelement->value = nbr;
	ft_lstadd_back(stack_a, newelement);
	return (1);
}

void	check_is_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = (*stack_a);
	if ((*stack_a) == NULL || (*stack_b) != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (temp->next != NULL)
	{
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			break ;
	}
	if (temp->next == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	free_stacks(t_list **stack_a, t_list **stack_b, char *line)
{
	if (*stack_a)
		ft_lstclear(stack_a, free);
	if (*stack_b)
		ft_lstclear(stack_b, free);
	if (line)
		free(line);
	return (0);
}
