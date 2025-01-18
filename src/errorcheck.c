/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaissramirez <kaissramirez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:21:57 by karamire          #+#    #+#             */
/*   Updated: 2025/01/18 06:04:26 by kaissramire      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *av)
{
	int	i;
	int	len;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && ft_isdigit(av[i + 1]))
		i++;
	len = ft_strlen(av);
	while (av[i] != '\0')
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	duplicate_error(t_list *stack_a, int nb)
{
	t_list	*check;

	check = stack_a;
	while (check != NULL)
	{
		if (check->value == nb)
			return (-1);
		check = check->next;
	}
	return (1);
}

void	print_stack(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d -> ", current->pos);
		current = current->next;
	}
	printf("NULL");
}

int	check_pos_right(t_list **stack_a)
{
	t_list	*current;

	current = (*stack_a);
	while (current->next != NULL)
	{
		if ((current->value) > (current->next->value))
			return (0);
		current = current->next;
	}
	return (1);
}

void	check_stack(t_list **stack_a, int ac, char **av)
{
	int		i;
	int		nbr;
	t_list	**stack_b;

	stack_b = malloc(sizeof(t_list));
	i = 0;
	while (++i < ac)
	{
		if (!syntax_error(av[i]))
		{
			write(1, "synta", 5);
			return ;
		}
		nbr = ft_atoi(av[i]);
		if (duplicate_error(*stack_a, nbr) == -1)
		{
			write(1, "Error", 5);
			return ;
		}
		put_in_stack_a(stack_a, nbr, i);
		put_pos(stack_a);
	}
	/* 	put_in_stack_b(stack_b);
		printf("a = ");
		print_stack(*stack_a);
		printf("\n");
		printf("b = ");
		print_stack(*stack_b);
		printf("\n");
		rrr(stack_a, stack_b);
		printf("\n");
		printf("a = ");
		print_stack(*stack_a);
		printf("\n");
		printf("b = ");
		print_stack(*stack_b); */
}
