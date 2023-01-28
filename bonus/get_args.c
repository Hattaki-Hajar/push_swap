/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:07:42 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/26 20:26:06 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	ints(char *all, t_stack *a)
{
	char	**arg;
	int		i;
	int		s;

	arg = ft_split(all, ' ');
	s = 0;
	while (arg[s])
		s++;
	a->head = ft_lstnew(ft_atoi(arg[0]));
	a->stack = a->head;
	i = 1;
	a->size = 1;
	while (arg[i])
	{
		ft_lstadd_back(&(a)->head, ft_lstnew(ft_atoi(arg[i])));
		a->head = a->head->next;
		a->size++;
		i++;
	}
	a->head = a->stack;
	ft_free(arg);
}

void	get_arg_bonus(int ac, char **av, t_stack *a)
{
	int		i;
	char	*all;

	i = 0;
	all = 0;
	while (++i < ac)
	{
		all = ft_strjoin(all, " ");
		if (!av[i][0])
			ft_error_bonus();
		all = ft_strjoin(all, av[i]);
	}
	final_check_bonus(all);
	ints(all, a);
	ft_check_duplicate_bonus(*a);
	free(all);
}
