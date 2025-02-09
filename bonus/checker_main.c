/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:45:20 by karamire          #+#    #+#             */
/*   Updated: 2025/02/09 07:06:21 by karamire         ###   ########.fr       */
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

int	do_command(t_list **stack_a, t_list **stack_b, char *input)
{
	if (ft_strcmp("sa\n", input) == 0 && *stack_a != NULL)
		sa(stack_a, 0);
	else if (ft_strcmp("sb\n", input) == 0 && *stack_b != NULL)
		sb(stack_b, 0);
	else if (ft_strcmp("ss\n", input) == 0 && *stack_a != NULL)
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp("ra\n", input) == 0 && *stack_a != NULL)
		ra(stack_a, 0);
	else if (ft_strcmp("rb\n", input) == 0 && *stack_b != NULL)
		rb(stack_b, 0);
	else if (ft_strcmp("rr\n", input) == 0 && *stack_a != NULL)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp("pa\n", input) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp("pb\n", input) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp("rra\n", input) == 0 && *stack_a != NULL)
		rra(stack_a, 0);
	else if (ft_strcmp("rrb\n", input) == 0 && *stack_a != NULL)
		rrb(stack_b, 0);
	else if (ft_strcmp("rrr\n", input) == 0)
		rrr(stack_a, stack_b, 0);
	else
		return (-1);
	return (1);
}
int	check_params(char *str)
{
	if (ft_strcmp("sa\n", str) == 0 || ft_strcmp("sb\n", str) == 0
		|| ft_strcmp("ss\n", str) == 0 || ft_strcmp("pa\n", str) == 0
		|| ft_strcmp("pb\n", str) == 0 || ft_strcmp("ra\n", str) == 0
		|| ft_strcmp("rb\n", str) == 0 || ft_strcmp("rr\n", str) == 0
		|| ft_strcmp("rra\n", str) == 0 || ft_strcmp("rrb\n", str) == 0
		|| ft_strcmp("rrr\n", str) == 0)
		return (1);
	else
		return (-1);
}

void	print_stack(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

int	check_input(t_list **stack_a, t_list **stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input != NULL)
	{
		if (check_params(input) == -1)
			return (-1);
		do_command(stack_a, stack_b, input);
		free(input);
		input = get_next_line(0);
	}
	free(input);
	check_is_sort(stack_a);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (check_stack(&stack_a, ac, av) == -1)
		return (-1);
	if (check_input(&stack_a, &stack_b) == -1)
		return (write(2, "Error\n", 6));
	if (stack_a)
		free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
	return (0);
}
