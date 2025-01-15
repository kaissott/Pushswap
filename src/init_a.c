/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:45:08 by karamire          #+#    #+#             */
/*   Updated: 2025/01/15 15:46:07 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_in_stack_a(t_list **stack_a, int nbr, int i)
{
	t_list *newelement;
	t_list *temp;

	newelement = malloc(sizeof(t_list));
	if (newelement == NULL)
		return;
	newelement->value = nbr;
	//newelement = stack_a->next;
	newelement->next = *stack_a;
	*stack_a = newelement;
}

