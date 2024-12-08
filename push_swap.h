/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:34:39 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/08 17:43:12 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					data;
	int					index;
	int					push_cost;
	bool				above_med;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}						t_stack_node;

// initialization
long					ft_atol(char *s);
void					append_node(t_stack_node **stack, int n);
t_stack_node			*split_to_stack(char *s, char c);
void					args_to_stack(t_stack_node **a, char **av);
bool					check_args(t_stack_node *stack, char **av);

// sorting library
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					pa(t_stack_node *a, t_stack_node *b, bool print);
void					pb(t_stack_node *a, t_stack_node *b, bool print);

//
bool					is_sorted(t_stack_node *a);
int						stack_length(t_stack_node *a);
t_stack_node			*last_node(t_stack_node *a);
t_stack_node			*min_node(t_stack_node *a);
t_stack_node			*max_node(t_stack_node *a);

t_stack_node			*sort_three(t_stack_node *a);
t_stack_node			*sort_stack(t_stack_node *a, t_stack_node *b);

// error handling
void					free_stack(t_stack_node *a);
void					error_handling(t_stack_node *a);

#endif