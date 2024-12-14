/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:51 by junjun            #+#    #+#             */
/*   Updated: 2024/12/14 23:21:28 by junjun           ###   ########.fr       */
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
	if (!*dst)
	{
		*dst = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dst;
		*dst = temp;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
