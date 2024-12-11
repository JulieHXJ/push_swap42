/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:51 by junjun            #+#    #+#             */
/*   Updated: 2024/12/11 15:45:56 by junjun           ###   ########.fr       */
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
