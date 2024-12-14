

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int	len;

	a = NULL;
	b = NULL;
	if (ac <= 1 || !*av[1])
		return (-1);
	else if (ac == 2)
		a = split_to_stack(av[1], ' ');
	else
		args_to_stack(a, av);
	len = stack_length(a);
	if (!is_sorted(a))
	{
		if (len <= 3)
			sort_three(a);
		else if (len > 3 && len < 6)
			sort_five(a, b);
		else
			radix_sort(a, b, len);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
