/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:18:34 by amassias          #+#    #+#             */
/*   Updated: 2024/01/18 20:58:36 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ps.h
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-01-17
 * @copyright Copyright (c) 2024
 */

#ifndef PS_H
# define PS_H

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

# include <stdint.h>

/* ************************************************************************** */
/*                                                                            */
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

# define OP_NOP 0x0
# define OP_SA 0x1
# define OP_SB 0x2
# define OP_SS 0x3
# define OP_PA 0x4
# define OP_PB 0x5
# define OP_RA 0x6
# define OP_RB 0x7
# define OP_RR 0x8
# define OP_RRA 0x9
# define OP_RRB 0xA
# define OP_RRR 0xB

/* ************************************************************************** */
/*                                                                            */
/* Header protoypes                                                           */
/*                                                                            */
/* ************************************************************************** */

void	p_sa(
			t_ps_context *context
			);

void	p_sb(
			t_ps_context *context
			);

void	p_ss(
			t_ps_context *context
			);

void	p_pa(
			t_ps_context *context
			);

void	p_pb(
			t_ps_context *context
			);

void	p_ra(
			t_ps_context *context
			);

void	p_rb(
			t_ps_context *context
			);

void	p_rr(
			t_ps_context *context
			);

void	p_rra(
			t_ps_context *context
			);

void	p_rrb(
			t_ps_context *context
			);

void	p_rrr(
			t_ps_context *context
			);

void	process_code(
			uint64_t code,
			t_ps_context *context
			);

void	sort_for_2(
			t_ps_context *context
			);

void	sort_for_3(
			t_ps_context *context
			);

void	sort_for_4(
			t_ps_context *context
			);

void	sort_for_5(
			t_ps_context *context
			);

void	radix_sort(
			t_ps_context *context
			);

#endif