/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:45:08 by karamire          #+#    #+#             */
/*   Updated: 2025/01/13 12:08:31 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_in_stack_a(t_list **stack_a, int nbr)
{
	t_list *newelement;

	newelement = malloc(sizeof(newelement));
	if (newelement == NULL)
		return;
	newelement->value = nbr;
	newelement->next = NULL;
	if (!(*stack_a))
	{
		stack_a = newelement;
	}
	else
	

}

void	init_a(t_list **stack_a, char **argv)
{
	int	i;
	int	nbr;

	i = 0;
	while(argv[i] != NULL)
	{
		if (!syntax_error(argv[i]))
			return;
		nbr = ft_atoi(argv[i]);
		if (!duplicate_error(*stack_a, nbr))
			return;
		put_in_stack_a(*stack_a, nbr);
	}
}
