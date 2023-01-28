/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:46:49 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/28 01:36:57 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"
#include<stdio.h>

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		exit(0);
	b.head = 0;
	b.stack = 0;
	b.size = 0;
	a.head = 0;
	a.stack = 0;
	a.size = 0;
	get_arg_bonus(ac, av, &a);
	read_inst(&a, &b);
}
