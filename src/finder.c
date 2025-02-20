/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:21:21 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/10 18:21:21 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_unrank(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->revalue == -1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*small;

	tmp = stack;
	small = find_unrank(stack);
	while (tmp)
	{
		if (tmp->revalue == -1 && tmp->content > small->content)
			small = tmp;
		tmp = tmp->next;
	}
	return (small);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = stack;
	max = find_unrank(stack);
	while (tmp)
	{
		if (tmp->revalue == -1 && tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
