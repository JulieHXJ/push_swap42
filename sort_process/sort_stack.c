/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:22 by junjun            #+#    #+#             */
/*   Updated: 2024/12/15 21:06:03 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_five(t_stack **a, t_stack **b)
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
	while (stack_length(*b) > 0)
		pa(a, b, false);
}

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

void	radix_sort(t_stack **a, t_stack **b, int len)
{
	int		*arr;
	int		digit;
	t_stack	*node;

	arr = sort_arr(*a, len);
	init_index(*a, arr);
	free_arr(arr);
	digit = 1;
	while (((len - 1) / digit) > 0)
	{
			node = *a;
			while (node)
			{
				// firstly push all 0 to stack b
				if ((node->targ_index / digit) % 3 == 0) 
				{
					to_top(a, node);
					pb(a, b,false);
					node = *a;
				}
				else
				{
					node = node->next;
				}
			}
			node = *a;
			while (node)
			{
				if ((node->targ_index / digit) % 3 == 1) 
				{
					// push 1 to stack b
					pb(a, b, false); 
					node = *a;
				} 
				else
				{
					// if node->targ_index / digit) % 3 ==  2: ra
					ra(a, false); 
					node = *a;
				}
					
			}
		
		while (stack_length(*b) > 0)
			pa(a, b, false);
		digit *= 3;
	}
}

/*
merge sort
*/
// static t_stack	*split_list(t_stack *head)
// {
// 	t_stack	*slow;
// 	t_stack	*fast;
// 	t_stack	*mid;

// 	if (!head || !head->next)
// 		return (NULL);
// 	slow = head;
// 	fast = head;
// 	while (fast->next && fast->next->next)
// 	{
// 		slow = slow->next;
// 		fast = fast->next->next;
// 	}
// 	mid = slow->next;
// 	// slow->next = NULL;
// 	// if (mid)
// 	// 	mid->prev = NULL;
// 	return (mid);
// }

// // merge the sorted lists
// static void	merge_lists(t_stack **a, t_stack **b, t_stack *l1, t_stack *l2)
// {
// 	while (l1 && l2)
// 	{
// 		if (l1->data <= l2->data)
// 		{
// 			push_pop(a, b, l1, false);
// 			l1 = *a;
// 		}
// 		else
// 		{
// 			push_pop(a, b, l2, false);
// 			l2 = *a;
// 		}
// 	}
// 	while (l1)
// 	{
// 		push_pop(a, b, l1, false);
// 		l1 = *a;
// 	}
// 	while (l2)
// 	{
// 		push_pop(a, b, l2, false);
// 		l2 = *a;
// 	}
// 	while (*b)
// 		pa(a, b, false);
// }

// void	merge_sort(t_stack **a, t_stack **b)
// {
// 	t_stack	*mid;
// 	t_stack	*first;

// 	if (!(*a) || !(*a)->next)
// 		return ;
// 	mid = split_list(*a);
// 	first = *a;
// 	merge_sort(&first, b);
// 	merge_sort(&mid, b);
// 	merge_lists(a, b, first, mid);
// }
