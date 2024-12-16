/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:41 by junjun            #+#    #+#             */
/*   Updated: 2024/12/16 18:55:12 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
check if stack a is already in right order
*/
bool	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (false);
		a = a->next;
	}
	return (true);
}

static bool	cmd_error(char *s)
{
	if (!s || !*s)
		return (true);
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (true);
		s++;
	}
	return (false);
}

static bool	is_dup(t_stack *stack, int n)
{
	while (stack)
	{
		if (stack->data == n)
			return (true);
		stack = stack->next;
	}
	return (false);
}

bool	append_node(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*last;

	if (!stack)
		return (false);
	new = malloc(sizeof(t_stack) * 1);
	if (!new)
		return (false);
	new->next = NULL;
	new->data = n;
	if (!*stack)
		*stack = new;
	else
	{
		last = last_node(*stack);
		last->next = new;
	}
	return (true);
}

/*
take arguments to initialize the stack a.
*/
void	args_to_stack(t_stack **a, char **av)
{
	long	nbr;
	int		i;

	i = 1;
	while (av[i])
	{
		if (cmd_error(av[i]))
			error_free(*a, NULL);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(*a, NULL);
		if (is_dup(*a, (int)nbr))
			error_free(*a, NULL);
		if (!append_node(a, (int)nbr))
			error_free(*a, NULL);
		i++;
	}
}
