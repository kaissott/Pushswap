/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:45:20 by karamire          #+#    #+#             */
/*   Updated: 2025/02/09 04:47:29 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	do_command(t_list **stack_a, t_list **stack_b, char *input)
{
	if (ft_strcmp("sa", input) == 0 && stack_a != NULL)
		sa(stack_a, 1);
	if (ft_strcmp("sb", input) == 0 && stack_b != NULL)
		sb(stack_b, 1);
	if (ft_strcmp("ss", input) == 0 && stack_a != NULL)
		ss(stack_a, stack_b);
	if (ft_strcmp("ra", input) == 0 && stack_a != NULL)
		ra(stack_a, 1);
	if (ft_strcmp("rb", input) == 0 && stack_b != NULL)
		rb(stack_b, 1);
	if (ft_strcmp("rr", input) == 0 && stack_a != NULL)
		rr(stack_a, stack_b);
	if (ft_strcmp("pa", input) == 0)
		pa(stack_a, stack_b);
	if (ft_strcmp("pb", input) == 0)
		pb(stack_a, stack_b);
	if (ft_strcmp("rra", input) == 0 && stack_a != NULL)
		rra(stack_a, 1);
	if (ft_strcmp("rrb", input) == 0 && stack_a != NULL)
		rrb(stack_a, 1);
	if (ft_strcmp("rrr", input) == 0)
		rrr(stack_a, stack_b);
}
int	check_params(char *str)
{
	if (ft_strcmp("sa", str) == 0 || ft_strcmp("sb", str) == 0
		|| ft_strcmp("ss", str) == 0 || ft_strcmp("pa", str) == 0
		|| ft_strcmp("pb", str) == 0 || ft_strcmp("ra", str) == 0
		|| ft_strcmp("rb", str) == 0 || ft_strcmp("rr", str) == 0
		|| ft_strcmp("rra", str) == 0 || ft_strcmp("rrb", str) == 0
		|| ft_strcmp("rrr", str) == 0)
		return (1);
	else
		return (-1);
}

int	check_input(t_list **stack_a, t_list **stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input != NULL)
	{
		if (!check_params(input))
			return (-1);
		do_command(stack_a, stack_b, input);
		input = get_next_line(0);
	}
	check_is_sort(stack_a);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = malloc(1 * sizeof(t_list));
	if (!stack_b)
		return (NULL);
	if (ac < 2)
		return (0);
	if (check_stack(&stack_a, ac, av) == -1)
		return (-1);
	check_input(&stack_a, &stack_b);
	free_stack(&stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
