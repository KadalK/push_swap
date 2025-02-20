/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:10:35 by kapinarc          #+#    #+#             */
/*   Updated: 2025/02/13 16:10:35 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_int(char *str)
{
	int			i;
	ssize_t		res;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648)
		return (0);
	return (1);
}

int	check_no_double(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (i == j)
				j++;
			if (av[i] && av[j] && ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_param(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (ft_strlen(av[i]) == 0)
			return (0);
		while (av[i][j])
		{
			if (!check_int(av[i]))
				return (0);
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-')
				return (0);
			else if (av[i][j] == '-' && ft_isdigit(av[i][j + 1]) == 0)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}
