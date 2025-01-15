/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:39:39 by karamire          #+#    #+#             */
/*   Updated: 2025/01/15 15:50:56 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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
void	check_stack(t_list **stack_a, int ac, char **argv);
void	put_in_stack_a(t_list **stack_a, int nbr, int i);
void	sa(t_list **stack_a);

#endif
