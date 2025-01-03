/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:22 by junjun            #+#    #+#             */
/*   Updated: 2024/12/21 19:11:28 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
give the target index of stack node base on sorted array
*/
static void	init_index(t_stack *a, int *arr)
{
	int		i;
	t_stack	*temp;
	int		len;

	temp = a;
	len = stack_length(a);
	while (temp)
	{
		i = 0;
		while (i < len)
		{
			if (temp->data == arr[i])
			{
				temp->targ_index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

static void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = max_node(*a);
	if (is_sorted(*a))
		return ;
	if (stack_length(*a) == 2)
		sa(a, false);
	else if (stack_length(*a) == 3)
	{
		if (max == *a)
			ra(a, false);
		else if (max == (*a)->next)
			rra(a, false);
		if ((*a)->data > (*a)->next->data)
			sa(a, false);
	}
}

void	insert_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;

	if (is_sorted(*a))
		return ;
	if (stack_length(*a) <= 3)
	{
		sort_three(a);
		return ;
	}
	while (stack_length(*a) > 3)
	{
		min = min_node(*a);
		to_top(a, min);
		pb(a, b, false);
	}
	sort_three(a);
	while (*b)
		pa(a, b, false);
}

/*
ksort base on sorted array index
*/
void	ksort_to_b(t_stack **a, t_stack **b, int len)
{
	int	i;
	int	range;
	int	*arr;

	i = 0;
	range = square_root(len) * 14 / 10;
	arr = sort_arr(*a, len);
	init_index(*a, arr);
	free_int_arr(arr);
	while (*a)
	{
		if ((*a)->targ_index <= i)
		{
			pb(a, b, false);
			rb(b, false);
			i++;
		}
		else if ((*a)->targ_index <= i + range)
		{
			pb(a, b, false);
			i++;
		}
		else
			ra(a, false);
	}
}

void	ksort_to_a(t_stack **a, t_stack **b)
{
	t_stack	*max;

	while (*b)
	{
		max = max_node(*b);
		to_top_b(b, max);
		pa(a, b, false);
	}
}

/*
 * radix sort with binary bits then changed to
 * ternary bits but still can't reach 700
 */
// void	radix_sort(t_stack **a, t_stack **b, int len)
// {
// 	int	*arr;
// 	int	digit;
// 	int	num;
// 	int	count;

// 	arr = sort_arr(*a, len);
// 	init_index(*a, arr);
// 	free_int_arr(arr);
// 	digit = 1;
// 	while (((len - 1) / digit) > 0)
// 	{
// 		num = 0;
// 		count = len;
// 		while (count--)
// 		{
// 			if (((*a)->targ_index / digit) % 3 == 0)
// 				pb(a, b, false);
// 			else if (((*a)->targ_index / digit) % 3 == 1)
// 			{
// 				pb(a, b, false);
// 				rb(b, false);
// 				num++;
// 			}
// 			else
// 				ra(a, false);
// 		}
// 		while (num--)
// 		{
// 			rrb(b, false);
// 			pa(a, b, false);
// 		}
// 		while (*b)
// 			pa(a, b, false);
// 		digit *= 3;
// 	}
// }
