/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:18:34 by amassias          #+#    #+#             */
/*   Updated: 2024/01/22 01:32:18 by amassias         ###   ########.fr       */
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