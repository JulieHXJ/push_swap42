/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:22 by junjun            #+#    #+#             */
/*   Updated: 2024/12/14 23:37:44 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*sort_three(t_stack **a)
{
	t_stack	*max;

	max = max_node(*a);
	if (is_sorted(*a))
		return ;
	if (stack_length(*a) == 2)
		sa(*a, false);
	else if (stack_length(*a) == 3)
	{
		if (max == *a)
			ra(a, false);
		else if (max == (*a)->next)
			rra(a, false);
		if ((*a)->data > (*a)->next->data)
			sa(*a, false);
	}
}

void	*sort_five(t_stack **a, t_stack **b)
{
    t_stack *min;
	
	if (is_sorted(*a))
		return ;
    while (stack_length(a) > 3)
    {
        min = min_node(*a);
        to_top(a, min);
        pb(a, b, false);
    }
	sort_three(a);
    while (stack_length(b) > 0)
       pb(a, b, false);
}

/*
give the target index of stack node base on sorted array
*/
static void	init_index(t_stack *a, int *arr)
{
	int i;
	t_stack *temp;
	int len;

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
				break;
			}
			i++;
		}
		temp = temp->next;
	}
}


// void	radix_sort(t_stack **a, t_stack **b, int len)
// {
//     int *arr;
//     int digit;
//     int i;
//     t_stack *node;
    
//     arr = sort_arr(a);
// 	init_index(*a, arr);
//     free_arr(arr);
//     digit = 1;
//     while (((len - 1) / digit) > 0)
//     {
//         i = 0;
//         while (i <= 9)
//         {
//             node = *a;
//             while (node)
//             {
//                 if ((node->targ_index / digit) % 10 == i)
//                 {
//                     to_top(a, node);
//                     pb(a, b, false);
//                 }
//                 node = node->next;
//             }
//             i++;
//         }
//         while (stack_length(b) > 0)
//             pa(a, b, false);
//         digit *= 10;
//     }
// }

/*
merge sort
*/
t_stack *split_list(t_stack *head)
{
    t_stack *slow = head;
    t_stack *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next; // slow pointer jump one node
        fast = fast->next->next; //fast pointer jump two nodes
    }
    t_stack *mid = slow->next;
    slow->next = NULL;
    return (mid);
}

//merge the sorted lists
t_stack *merge_lists(t_stack **a, t_stack **b, t_stack *l1, t_stack *l2)
{
    while (l1 && l2)
    {
        if (l1->data <= l2->data)
        {
            pb(&l1, b, false);
        }
        else
        {
            pb(&l2, b, false);
        }
    }
    while (l1)
    {
        pb(&l1, b, false);
    }
    while (l2)
    {
        pb(&l2, b, false);
    }
    while (*b)
    {
        pa(a, b, false);
    }
}

void merge_sort(t_stack **a, t_stack **b)
{
    if (!(*a) || !(*a)->next)
    {
        return;
    }
    t_stack *mid = split_list(*a);
    // first half from *a , last half from &mid, stack b is for storage temp
    merge_sort(a, b);
    merge_sort(&mid, b);
    merge_lists(a, b, *a, mid);
}