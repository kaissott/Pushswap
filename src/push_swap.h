
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karamire <karamire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:39:39 by karamire          #+#    #+#             */
/*   Updated: 2025/01/28 18:18:29 by karamire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strcat(char *dst, const char *src);
int					syntax_error(char *arg);
int					duplicate_error(t_list *stack_a, int nb);
int					sort_stack(int ac, t_list **stack_a, t_list **stack_b);
int					list_size(t_list *stack);
int					chunk_size_calc(int list_size);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					check_stack(t_list **stack_a, int ac, char **argv);
int					put_in_stack_a(t_list **stack_a, int nbr);
size_t				ft_strlen(const char *s);
t_list				*ft_lstlast(t_list *lst);
void				sa(t_list **stack_a, int p);
void				sb(t_list **stack_b, int p);
void				ss(t_list **stack_a, t_list **stack_b, int i);
void				pa(t_list **stack_a, t_list **stack_b, int i);
void				pb(t_list **stack_a, t_list **stack_b, int i);
void				ra(t_list **stack_a, int p);
void				rb(t_list **stack_b, int p);
void				rr(t_list **stack_a, t_list **stack_b, int i);
void				rra(t_list **stack_a, int p);
void				rrb(t_list **stack_b, int p);
void				rrr(t_list **stack_a, t_list **stack_b, int i);
void				sort_stack_two(t_list **stack_a);
void				sort_stack_max(t_list **stack_a, t_list **stack_b);
void				sort_stack_three(t_list **stack_a);
void				sort_stack_five(t_list **stack_a, t_list **stack_b, int i);
void				search_and_push_min_two(t_list **stack_a, t_list **stack_b,
						int pos, int i);
int					return_error(t_list **stack_a, char **temp);
void				search_and_push_min(t_list **stack_a, t_list **stack_b);
void				stack_index(t_list **stack_a);
void				free_stack(t_list **stack);
void				first_push(t_list **stack_a, t_list **stack_b, int chunk,
						int i);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
