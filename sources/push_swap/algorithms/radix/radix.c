/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:03:36 by amassias          #+#    #+#             */
/*   Updated: 2024/01/18 18:52:22 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file radix.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-01-18
 * @copyright Copyright (c) 2024
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdbool.h>

/* ************************************************************************** */
/*                                                                            */
/* Helper protoypes                                                           */
/*                                                                            */
/* ************************************************************************** */

static size_t	bit_width(
					size_t x
					);

static size_t	__radix(
					t_ps_context *context,
					int mask,
					bool is_base_b
					);

static void		_roll_back(
					t_ps_context *context,
					bool is_base_b
					);

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

void	radix_sort(
			t_ps_context *context
			)
{
	size_t	i;
	size_t	pushed;
	size_t	itr_count;
	bool	is_base_b;

	i = 0;
	is_base_b = false;
	itr_count = bit_width(context->count) + 1;
	while (i < itr_count)
	{
		pushed = __radix(context, 1 << i, is_base_b);
		if (pushed >= context->count / 2)
			is_base_b ^= true;
		if (++i == itr_count)
			is_base_b = false;
		_roll_back(context, is_base_b);
	}
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

static size_t	bit_width(
					size_t x
					)
{
	static const size_t	size_t_size = sizeof(size_t) * 8;
	size_t				n;

	n = 0;
	while (!(x & (1UL << (size_t_size - 1))))
	{
		++n;
		x <<= 1;
	}
	return (size_t_size - n - 1);
}

static size_t	__radix(
					t_ps_context *context,
					int mask,
					bool is_base_b
					)
{
	size_t	j;
	size_t	count;
	t_list	**head;
	void	(*push)(t_ps_context *);
	void	(*rotate)(t_ps_context *);

	head = &context->a;
	push = p_pb;
	rotate = p_ra;
	if (is_base_b)
	{
		head = &context->b;
		push = p_pa;
		rotate = p_rb;
	}
	count = 0;
	j = 0;
	while (j++ < context->count)
	{
		if (is_base_b ^ (((*(int *)(*head)->content) & mask) != 0))
			rotate(context);
		else
			(push(context), ++count);
	}
	return (count);
}

static void	_roll_back(
				t_ps_context *context,
				bool is_base_b
				)
{
	void	(*push)(t_ps_context *);
	t_list	**head;

	push = p_pa;
	head = &context->b;
	if (is_base_b)
	{
		push = p_pb;
		head = &context->a;
	}
	while (*head)
		push(context);
}
