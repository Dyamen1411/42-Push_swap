/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:26:36 by amassias          #+#    #+#             */
/*   Updated: 2024/01/17 19:27:34 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file reverse_rotate.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-01-17
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
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

void	p_rra(
			t_ps_context *context
			)
{
	ft_putstr("rra\n");
	ps_rra(context);
}

void	p_rrb(
			t_ps_context *context
			)
{
	ft_putstr("rrb\n");
	ps_rrb(context);
}

void	p_rrr(
			t_ps_context *context
			)
{
	ft_putstr("rrr\n");
	ps_rrr(context);
}
