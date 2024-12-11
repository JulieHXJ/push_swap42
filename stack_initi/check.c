/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:45 by junjun            #+#    #+#             */
/*   Updated: 2024/12/11 15:46:47 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	cmd_error(char *s)
{
	if (!s || !*s)
		return (true);
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (!(*s >= '0' && &s <= '9'))
			return (true);
		s++;
	}
	return (false);
}

static bool	is_dup(t_stack_node *stack, int n)
{
	t_stack_node	*temp;

	if (!stack)
	{
		return (false);
	}
	while (stack)
	{
		if (stack->data == n)
		{
			return (true);
		}
		stack = stack->next;
	}
	return (false);
}

void	error_free(t_stack_node **a)
{
	
}

/*
check input arguments or string ;
handle ,
*/
bool	check_args(t_stack_node *stack, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (cmd_error(av[i]))
		{
			error_free();
			return (false);
		}
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			error_handling();
			return (false);
		}
		if (is_dup(&stack, (int)nbr))
		{
			error_handling();
			return (false);
		}
		i++;
	}
	return (true);
}

/*
check if stack a is already in right order
*/
bool	is_sorted(t_stack_node *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (false);
		a = a->next;
	}
	return (true);
}
