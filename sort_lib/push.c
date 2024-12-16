/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:51 by junjun            #+#    #+#             */
/*   Updated: 2024/12/16 00:26:30 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else
	{
		temp->next = *dst;
		(*dst)->prev = temp;
		temp->prev = NULL;
		*dst = temp;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		ft_putendl_fd("pa", 2);
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (!print)
		ft_putendl_fd("pb", 2);
}

void	push_pop(t_stack **a, t_stack **b, t_stack *node, bool print)
{
	to_top(a, node);
	pb(a, b, print);
	// return (*a);
}
