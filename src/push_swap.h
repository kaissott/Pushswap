/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:39:39 by karamire          #+#    #+#             */
/*   Updated: 2025/01/26 16:14:22 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* typedef struct s_list
{
	int	value;
	int	cost;
	struct s_list *next;
}				t_list; */

int		syntax_error(char *arg);
int		duplicate_error(t_list *stack_a, int nb);
int		sort_stack(int ac, t_list **stack_a, t_list **stack_b);
int		check_pos_right(t_list **stack_a);
int		list_size(t_list *stack);
int		chunk_size_calc(int list_size);
void	check_stack(t_list **stack_a, int ac, char **argv);
void	put_in_stack_a(t_list **stack_a, int nbr, int i);
void	reset_pos(t_list **stack_a);
void	sa(t_list **stack_a, int p);
void	sb(t_list **stack_b, int p);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, int p);
void	rb(t_list **stack_b, int p);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int p);
void	rrb(t_list **stack_b, int p);
void	rrr(t_list **stack_a, t_list **stack_b);
void	sort_stack_two(t_list **stack_a);
void	sort_stack_max(t_list **stack_a, t_list **stack_b);
void	sort_stack_three(t_list **stack_a);
void	sort_stack_five(t_list **stack_a, t_list **stack_b);
void	search_and_push_min_two(t_list **stack_a, t_list **stack_b, int pos,
			int i);
void	search_and_push_min(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstlast(t_list *lst);
void	print_stack(t_list *stack);
void	stack_index(t_list **stack_a);

#endif
