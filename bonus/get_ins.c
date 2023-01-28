/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:26:54 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/28 01:36:49 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"
#include<stdio.h>

char	*get_inst(void)
{
	char	*ins;
	char	*s;

	ins = get_next_line(0);
	s = 0;
	while (ins)
	{
		s = ft_strjoin(s, ins);
		free (ins);
		ins = get_next_line(0);
	}
	return (s);
}

void	check_ins1(char	**ins, t_stack *a, t_stack *b, int i)
{
	if (!ft_strncmp(ins[i], "pa", ft_strlen(ins[i])))
		to_push(b, a);
	else if (!ft_strncmp(ins[i], "pb", ft_strlen(ins[i])))
		to_push(a, b);
	else if (!ft_strncmp(ins[i], "ss", ft_strlen(ins[i])))
		to_ss(a, b);
	else if (!ft_strncmp(ins[i], "rr", ft_strlen(ins[i])))
		to_rr(a, b);
	else if (!ft_strncmp(ins[i], "rrr", ft_strlen(ins[i])))
		to_rrr(a, b);
	else
		ft_error_bonus();
}

void	check_ins2(char	**ins, t_stack *a, t_stack *b, int i)
{
	while (ins && ins[i])
	{
		if (!ft_strncmp(ins[i], "sa", ft_strlen(ins[i])))
			to_swap(a);
		else if (!ft_strncmp(ins[i], "sb", ft_strlen(ins[i])))
			to_swap(b);
		else if (!ft_strncmp(ins[i], "ra", ft_strlen(ins[i])))
			to_rotate(a);
		else if (!ft_strncmp(ins[i], "rb", ft_strlen(ins[i])))
			to_rotate(b);
		else if (!ft_strncmp(ins[i], "rra", ft_strlen(ins[i])))
			to_rev_rotate(a);
		else if (!ft_strncmp(ins[i], "rrb", ft_strlen(ins[i])))
			to_rev_rotate(b);
		else
			check_ins1(ins, a, b, i);
		i++;
	}
}

void	read_inst(t_stack *a, t_stack *b)
{
	char	**ins;
	char	*op;
	int		i;

	op = get_inst();
	ins = ft_split(op, '\n');
	i = 0;
	check_ins2(ins, a, b, i);
	if (is_sorted_bonus(a) && b->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_free_bonus(ins);
	free(op);
}
