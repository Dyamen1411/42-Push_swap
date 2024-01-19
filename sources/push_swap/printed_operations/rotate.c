/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:27:55 by amassias          #+#    #+#             */
/*   Updated: 2024/01/17 19:28:42 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rotate.c
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

void	p_ra(
			t_ps_context *context
			)
{
	ft_putstr("ra\n");
	ps_ra(context);
}

void	p_rb(
			t_ps_context *context
			)
{
	ft_putstr("rb\n");
	ps_rb(context);
}

void	p_rr(
			t_ps_context *context
			)
{
	ft_putstr("rr\n");
	ps_rr(context);
}
