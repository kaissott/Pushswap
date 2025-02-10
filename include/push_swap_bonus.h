/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:58:21 by karamire          #+#    #+#             */
/*   Updated: 2025/02/10 10:51:59 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../bonus/get_next_line.h"
# include "../src/push_swap.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		put_in_stack_a(t_list **stack_a, int nbr);
void	check_is_sort(t_list **stack_a, t_list **stack_b);
int		check_input(t_list **stack_a, t_list **stack_b);
/* int		check_params(char *str); */
int		free_stacks(t_list **stack_a, t_list **stack_b, char *line);

#endif
