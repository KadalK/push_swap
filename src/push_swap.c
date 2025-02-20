/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:47:55 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/12 20:06:09 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	if (check_param(av) == 0 || check_no_double(av) != 1)
		return (ft_putendl_fd("Error\nPut valid arguments !", 2), 1);
	a = ft_add_value_list(ac, av);
	if (ft_stack_size(a) <= 5)
		lil_sort(&a, &b);
	radix_sort(&a, &b);
	ft_freestack(a);
	ft_freestack(b);
	return (0);
}
