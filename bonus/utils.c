/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:25:43 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/28 02:20:36 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void	ft_error_bonus(void)
{
	ft_putendl_fd("Error", 2);
	exit(-1);
}

void	ft_free_bonus(char **av)
{
	int	i;

	i = 0;
	while (av && av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	is_sorted_bonus(t_stack *stack)
{
	t_list	*temp;
	t_list	*iter;

	iter = stack->head;
	while (iter)
	{
		temp = iter->next;
		while (temp)
		{
			if (iter->content > temp->content)
				return (0);
			temp = temp->next;
		}
		iter = iter->next;
	}
	return (1);
}
