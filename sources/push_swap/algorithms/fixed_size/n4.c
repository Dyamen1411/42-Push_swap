/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:15:42 by amassias          #+#    #+#             */
/*   Updated: 2024/01/18 23:29:16 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file n4.c
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

/* ************************************************************************** */
/*                                                                            */
/* Global variables                                                           */
/*                                                                            */
/* ************************************************************************** */

static const uint64_t	g_func[] = {
[(0 << 6) | (1 << 4) | (2 << 2) | 3] = 0x0000000000000000UL,
[(0 << 6) | (1 << 4) | (3 << 2) | 2] = 0x0000000000099166UL,
[(0 << 6) | (2 << 4) | (1 << 2) | 3] = 0x0000000000000916UL,
[(0 << 6) | (2 << 4) | (3 << 2) | 1] = 0x0000000000000019UL,
[(0 << 6) | (3 << 4) | (1 << 2) | 2] = 0x0000000000000061UL,
[(0 << 6) | (3 << 4) | (2 << 2) | 1] = 0x0000000000016616UL,
[(1 << 6) | (0 << 4) | (2 << 2) | 3] = 0x0000000000000001UL,
[(1 << 6) | (0 << 4) | (3 << 2) | 2] = 0x0000000000044355UL,
[(1 << 6) | (2 << 4) | (0 << 2) | 3] = 0x0000000000064959UL,
[(1 << 6) | (2 << 4) | (3 << 2) | 0] = 0x0000000000000009UL,
[(1 << 6) | (3 << 4) | (0 << 2) | 2] = 0x0000000000000161UL,
[(1 << 6) | (3 << 4) | (2 << 2) | 0] = 0x0000000000009916UL,
[(2 << 6) | (0 << 4) | (1 << 2) | 3] = 0x0000000000006619UL,
[(2 << 6) | (0 << 4) | (3 << 2) | 1] = 0x0000000000000616UL,
[(2 << 6) | (1 << 4) | (0 << 2) | 3] = 0x0000000000664915UL,
[(2 << 6) | (1 << 4) | (3 << 2) | 0] = 0x0000000000000091UL,
[(2 << 6) | (3 << 4) | (0 << 2) | 1] = 0x0000000000000066UL,
[(2 << 6) | (3 << 4) | (1 << 2) | 0] = 0x0000000000000199UL,
[(3 << 6) | (0 << 4) | (1 << 2) | 2] = 0x0000000000000006UL,
[(3 << 6) | (0 << 4) | (2 << 2) | 1] = 0x0000000000009199UL,
[(3 << 6) | (1 << 4) | (0 << 2) | 2] = 0x0000000000000016UL,
[(3 << 6) | (1 << 4) | (2 << 2) | 0] = 0x0000000000006495UL,
[(3 << 6) | (2 << 4) | (0 << 2) | 1] = 0x0000000000000661UL,
[(3 << 6) | (2 << 4) | (1 << 2) | 0] = 0x0000000000064915UL,
};

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

void	sort_for_4(
			t_ps_context *context
			)
{
	int	first;
	int	second;
	int	third;
	int	fourth;

	first = *(int *)context->a->content;
	second = *(int *)context->a->next->content;
	third = *(int *)context->a->next->next->content;
	fourth = *(int *)context->a->next->next->next->content;
	process_code(
		g_func[(first << 6) | (second << 4) | (third << 2) | (fourth)],
		context);
}

// 0x0 > no_op
// 0x1 > sa
// 0x2 > sb
// 0x3 > ss
// 0x4 > pa
// 0x5 > pb
// 0x6 > ra
// 0x7 > rb
// 0x8 > rr
// 0x9 > rra
// 0xA > rrb
// 0xB > rrr
// 0xC > undefined
// 0xD > undefined
// 0xE > undefined
// 0xF > undefined

// 2 1 0 3 -> why is it 6 and not max 5 like others ? am i dumb ???
