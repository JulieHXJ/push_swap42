/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:34:52 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/08 17:46:15 by xhuang           ###   ########.fr       */
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

static bool	is_dup(t_stack_node **stack, int n)
{
	t_stack_node	*temp;

	if (!stack || !*stack)
	{
		return (false);
	}
	temp = *stack;
	while (temp)
	{
		if (temp->data == n)
		{
			return (true);
		}
		temp = temp->next;
	}
	return (false);
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
			error_handling();
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
