/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:34:49 by kapinarc          #+#    #+#             */
/*   Updated: 2024/12/20 19:34:49 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	dec_to_bin(int n)
{
	long	div;
	long	mod;

	div = n / 2;
	mod = n % 2;
	if (div == 0)
		return (mod);
	else
		return (dec_to_bin (div) * 10 + mod);
}

t_stack	*ft_add_value_list(int ac, char **av)
{
	int		i;
	t_stack	*a;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		ft_stackadd_back(&a, ft_stacknew(ft_atoi(av[i])));
		i++;
	}
	pile_ranker(a);
	return (a);
}

char	*add_leading_zeros(const char *binary, int total_length)
{
	int		bin_len;
	int		zeros_to_add;
	char	*result;
	int		i;

	bin_len = ft_strlen(binary);
	zeros_to_add = total_length - bin_len;
	if (zeros_to_add <= 0)
		return (ft_strdup(binary));
	result = ft_calloc(total_length + 1, sizeof (char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < zeros_to_add)
		result[i++] = '0';
	while (*binary)
		result[i++] = *binary++;
	return (result);
}

void	pile_ranker(t_stack *a)
{
	int		i;
	t_stack	*small;
	char	*tmp;

	i = 0;
	while (i < ft_stack_size(a))
	{
		small = find_min(a);
		small->revalue = i;
		tmp = ft_itoa(dec_to_bin(i));
		small->bin = add_leading_zeros(tmp, MAX_BIN);
		i++;
		free(tmp);
	}
}

void	ft_freestack(t_stack *s)
{
	t_stack	*tmp;

	if (!s)
		return ;
	tmp = s;
	while (tmp || s)
	{
		tmp = s->next;
		if (s->bin)
			free(s->bin);
		free(s);
		s = tmp;
	}
}
