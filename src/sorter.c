/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:16:31 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/17 14:09:56 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_stack **a, t_stack **b)
{
	int	pos;
	int	i;
	int	size;

	pos = 8;
	size = ft_stack_size(*a);
	while (is_sorted(*a) == 0 && pos >= 0)
	{
		i = 0;
		while (i < size)
		{
			if ((*a)->bin[pos] == '1' && !is_sorted(*a))
				pb(a, b);
			else if ((*a)->bin[pos] == '0')
				ra(a);
			else if (is_sorted(*a) == 0)
				break ;
			i++;
		}
		while (*b != NULL)
			pa(b, a);
		pos--;
	}
}

int	is_sorted(t_stack *s)
{
	int		i;
	t_stack	*tmp;

	tmp = s;
	i = ft_stack_size(tmp) - 1;
	while (tmp != NULL)
	{
		if (i != tmp->revalue)
			return (0);
		tmp = tmp->next;
		i--;
	}
	return (1);
}

void	lil_sort(t_stack **a, t_stack **b)
{
	int	min;
	int	size;

	size = ft_stack_size(*a);
	min = ft_stack_size(*a) - 1;
	if (is_sorted(*a))
		return ;
	if (size == 2)
	{
		ra(a);
		return ;
	}
	while (ft_stack_size(*a) > 3)
	{
		if ((*a)->revalue == min || ((*a)->revalue == min - 1 && size == 5))
			pb(a, b);
		else
			ra(a);
	}
	lil_lil_sort(a);
	if (ft_stack_size(*b) > 1 && ((*b)->revalue > (*b)->next->revalue))
		rb(b);
	while (ft_stack_size(*b))
		pa(b, a);
}

void	lil_lil_sort(t_stack **a)
{
	t_stack	*mid;
	t_stack	*last;

	mid = (*a)->next;
	last = mid->next;
	if (is_sorted(*a))
		return ;
	else if (mid->revalue == 2 && last->revalue == 0)
	{
		sa(a);
	}
	else if (mid->revalue == 2 && last->revalue == 1)
		ra(a);
	else if (mid->revalue == 0 && last->revalue == 2)
		rra(a);
	else if (mid->revalue == 1 && last->revalue == 2)
	{
		sa(a);
		rra(a);
	}
	else if (mid->revalue == 0 && last->revalue == 1)
	{
		sa(a);
		ra(a);
	}
}
