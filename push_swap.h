/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:06:29 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/21 19:27:24 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				data;
	int				targ_index;
	bool			above_median;

	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// initialization
void				to_stack(t_stack **a, char **av);

// sorting library
void				sa(t_stack **a, bool print);
void				sb(t_stack **b, bool print);
void				ss(t_stack **a, t_stack **b, bool print);
void				ra(t_stack **a, bool print);
void				rb(t_stack **b, bool print);
void				rr(t_stack **a, t_stack **b, bool print);
void				rra(t_stack **a, bool print);
void				rrb(t_stack **b, bool print);
void				rrr(t_stack **a, t_stack **b, bool print);
void				pa(t_stack **a, t_stack **b, bool print);
void				pb(t_stack **a, t_stack **b, bool print);

// sorting argorithm
bool				is_sorted(t_stack *a);
int					stack_length(t_stack *a);
t_stack				*last_node(t_stack *a);
t_stack				*min_node(t_stack *a);
t_stack				*max_node(t_stack *a);
int					*sort_arr(t_stack *a, int len);
int					square_root(int n);
void				to_top(t_stack **stack, t_stack *node);
void				to_top_b(t_stack **stack, t_stack *node);

void				insert_sort(t_stack **a, t_stack **b);
// void				radix_sort(t_stack **a, t_stack **b, int len);
void				ksort_to_b(t_stack **a, t_stack **b, int len);
void				ksort_to_a(t_stack **a, t_stack **b);

// error handling
void				free_int_arr(int *arr);
void				free_str_arr(char **arr);
void				free_stack(t_stack *a);
void				error_free(t_stack *a, t_stack *b);

#endif