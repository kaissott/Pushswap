/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 04:21:34 by karamire          #+#    #+#             */
/*   Updated: 2025/02/09 04:43:06 by karamire         ###   ########.fr       */
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
		return (-1);
	newelement->value = nbr;
	ft_lstadd_back(stack_a, newelement);
	return (1);
}

void	check_is_sort(t_list **stack_a)
{
	int		size;
	int		i;
	t_list	*temp;

	i = 0;
	temp = (*stack_a);
	size = ft_lstsize(*stack_a);
	while (temp != NULL)
	{
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			break ;
		i++;
	}
	printf("%d\n", size);
	printf("%d\n", i);
	if (i == size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
