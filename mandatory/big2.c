/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:39:19 by hhattaki          #+#    #+#             */
/*   Updated: 2023/01/28 01:59:12 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_rb(t_stack *b, t_stack *a, int *arr, int len)
{
	int	r;

	r = 0;
	while (b->head->content != arr[len])
	{
		if (len > 0 && b->head->content == arr[len - 1])
		{
			push(b, a, 1);
			r = 1;
		}
		if (b->head->content == arr[len])
			return (r);
		rotate_b(b);
	}
	return (r);
}

int	to_rrb(t_stack *b, t_stack *a, int *arr, int len)
{
	int	r;

	r = 0;
	while (b->head->content != arr[len])
	{
		if (len > 0 && b->head->content == arr[len - 1])
		{
			push(b, a, 1);
			r = 1;
		}
		if (b->head->content == arr[len])
			return (r);
		rev_rotate(b, 1);
	}
	return (r);
}

int	to_push(t_stack *b, t_stack *a, int *arr, int len)
{
	int		found;
	int		r;

	found = search(*b, arr[len]);
	if (found == -1)
		return (-1);
	if (found <= b->size / 2)
		r = to_rb(b, a, arr, len);
	else
		r = to_rrb(b, a, arr, len);
	push(b, a, 1);
	if (r == 1)
		swap(a, 0);
	return (r);
}

void	upkid(t_stack *b, t_stack *a)
{
	int	min;

	min = b->stack->content;
	while (b->stack)
	{
		if (b->stack->content < min)
			min = b->stack->content;
		b->stack = b->stack->next;
	}
	b->stack = b->head;
	while (b->head->content != min)
	{
		rotate_b(b);
	}
	if (b->head->content == min)
	{
		push(b, a, 'b');
		rotate_a(a);
	}
}

void	b_to_a(int *arr, t_stack *a, t_stack *b, t_num *d)
{
	int		len;
	t_stack	temp;

	temp = *b;
	len = d->arg_num - 1;
	while (b->size > 0 && len >= 0)
	{
		to_push(b, a, arr, len);
		len--;
	}
	while (b->head)
		upkid(b, a);
}
