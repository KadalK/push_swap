/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:23:30 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/17 18:24:49 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define MAX_BIN 9

typedef struct s_stack
{
	struct s_stack	*next;
	int				content;
	int				revalue;
	char			*bin;
}	t_stack;

//checker.c
int		check_int(char *str);
int		check_no_double(char **av);
int		check_param(char **av);
int		check_bin(long nb);
//finder.c
t_stack	*find_min(t_stack *stack);
t_stack	*find_unrank(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_last(t_stack *stack);
//push.c
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
//push_swap_utils.c
int		dec_to_bin(int n);
t_stack	*ft_add_value_list(int ac, char **av);
char	*add_leading_zeros(const char *binary, int total_length);
void	pile_ranker(t_stack *a);
void	ft_freestack(t_stack *s);
//revers_rotate.c
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
//rotate.c
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
//sorter.c
void	radix_sort(t_stack **a, t_stack **b);
int		is_sorted(t_stack *s);
void	lil_sort(t_stack **a, t_stack **b);
void	lil_lil_sort(t_stack **a);
//stack.c
t_stack	*ft_stacknew(int content);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		ft_stack_size(t_stack *stack);
//swap.c
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif