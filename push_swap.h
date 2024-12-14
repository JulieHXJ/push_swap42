
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int					data;
	int					targ_index;

	struct s_stack	*next;
	struct s_stack	*prev;
}						t_stack;

// initialization
long					ft_atol(char *s);
void					append_node(t_stack **stack, int n);
t_stack			*split_to_stack(char *s, char c);
void					args_to_stack(t_stack **a, char **av);
bool					check_args(t_stack *stack, char **av);

// sorting library
void					sa(t_stack **a, bool print);
void					sb(t_stack **b, bool print);
void					ss(t_stack **a, t_stack **b, bool print);
void					ra(t_stack **a, bool print);
void					rb(t_stack **b, bool print);
void					rr(t_stack **a, t_stack **b, bool print);
void					rra(t_stack **a, bool print);
void					rrb(t_stack **b, bool print);
void					rrr(t_stack **a, t_stack **b, bool print);
void					pa(t_stack *a, t_stack *b, bool print);
void					pb(t_stack *a, t_stack *b, bool print);

//
bool					is_sorted(t_stack *a);
int						stack_length(t_stack *a);
t_stack			*last_node(t_stack *a);
t_stack			*min_node(t_stack *a);
t_stack			*max_node(t_stack *a);

void	*sort_three(t_stack **a);
void	*sort_five(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b, int len);
int	*sort_arr(t_stack *a);
void	to_top(t_stack **stack, t_stack *node);

// error handling
void					free_stack(t_stack *a);
void					error_handling(t_stack *a);

#endif