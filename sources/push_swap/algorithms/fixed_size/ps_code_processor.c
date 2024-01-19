/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_code_processor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:19:22 by amassias          #+#    #+#             */
/*   Updated: 2024/01/18 23:28:36 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ps_code_processor.c
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
/* Helper protoypes                                                           */
/*                                                                            */
/* ************************************************************************** */

static void	_do_nothing(
				t_ps_context *context
				);

/* ************************************************************************** */
/*                                                                            */
/* Global variables                                                           */
/*                                                                            */
/* ************************************************************************** */

void	(*g_functions[])(t_ps_context *) = {
[OP_NOP] = _do_nothing,
[OP_SA] = p_sa,
[OP_SB] = p_sb,
[OP_SS] = p_ss,
[OP_PA] = p_pa,
[OP_PB] = p_pb,
[OP_RA] = p_ra,
[OP_RB] = p_rb,
[OP_RR] = p_rr,
[OP_RRA] = p_rra,
[OP_RRB] = p_rrb,
[OP_RRR] = p_rrr,
};

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

void	process_code(
			uint64_t code,
			t_ps_context *context
			)
{
	while (code)
	{
		g_functions[code & 0xF](context);
		code >>= 4;
	}
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

static void	_do_nothing(
				t_ps_context *_
				)
{
	(void) _;
}
