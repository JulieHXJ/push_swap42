/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:22 by junjun            #+#    #+#             */
/*   Updated: 2024/12/16 11:44:20 by junjun           ###   ########.fr       */
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
	while (*b)
		pa(a, b, false);
}

void insertion_sort(t_stack **a, t_stack **b)
{
	int len;
	t_stack *cheapest;
	
	pb(a, b, false);
	len = stack_length(*a);
	//push b entil 3 left
	while (len--)
	{
		//找到stack b中biggest smaller 比他小的数中最大一个，移动到顶端。如果没有就找到最大值
		insert_b()
		// t_stack *biggest_smal = find_big_smal(b);//todo
		// to_top(b, biggest_smal);
		// pb(a, b, false);
		
	}
	while (*b)
	{
		pa(a, b, false);
	}
	if (!is_sorted(a))
	{
		t_stack *min = min_node(a);
		to_top(a, min);
	}
	
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
	int		num;
	int		count;

	arr = sort_arr(*a, len);
	init_index(*a, arr);
	free_arr(arr);
	digit = 1;
	while (((len - 1) / digit) > 0)
	{
		num = 0;
		count = len;
		while (count--)
		{
			if (((*a)->targ_index / digit) % 3 == 0) 
				pb(a, b,false);
			else if (((*a)->targ_index / digit) % 3 == 1) 
			{
				pb(a, b, false); 
				rb(b, false);
				num++;
			}
			else
				ra(a, false);
		}
		while (num--)
		{
			rrb(b, false);
			pa(a, b, false);
		}
		while (*b)
			pa(a, b, false);
		digit *= 3;
	}
}

//unfinished
void calc_push_cost(t_stack *stack) 
{
    t_stack *node = stack;

    while (node) 
	{
		
        // 计算将节点移动到 stack_a 顶部的成本
        int cost = cost_to_top(a, node);//todo
        // 如果是推送到 stack_b，无需考虑插入成本
        node->push_cost = cost;
        node = node->next;
    }
    node = b;
    while (node) {
        // 计算将节点从 stack_b 插回 stack_a 的成本
        int cost_to_top = calculate_cost_to_top(b, node);
        int cost_to_insert = calculate_cost_to_insert(a, node);

        node->push_cost = cost_to_top + cost_to_insert;

        node = node->next;
    }
}

t_stack *find_cheapest_node(t_stack *stack) {
    t_stack *node = stack;
    t_stack *cheapest = node;

    while (node) {
        if (node->push_cost < cheapest->push_cost)
            cheapest = node;
        node = node->next;
    }

    return cheapest;
}

void insert_b(t_stack **b, t_stack *a_node) {
    if (!*b || a_node->data > (*b)->data) {
        pb(b, a_node, false); // 如果 b 为空或 node 应插入栈顶，直接推入
    } else {
        // 找到biggest smaller 通过to_top移动到顶端
       
        pb(b, a_node, false); // 插入到合适位置
        while (*b && (*b)->value > node->value) {
            rrb(b, false); // 恢复栈顺序
        }
    }
}
