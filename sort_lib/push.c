/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:55:30 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/08 17:36:08 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*temp;

	if (!*src)
		return ;
	temp = *src;
	temp->prev = NULL;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	// push to dst
	if (!*dst)
	{
		// if dst is empty
		*dst = temp;
		temp->next = NULL;
	}
	else
	{
		// push to the top
		temp->next = *dst;
		temp->next->prev = temp;
		*dst = temp;
	}
}

void	pa(t_stack_node *a, t_stack_node *b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node *a, t_stack_node *b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
