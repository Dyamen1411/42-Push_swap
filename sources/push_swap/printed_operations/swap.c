/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:28:54 by amassias          #+#    #+#             */
/*   Updated: 2024/01/17 19:29:39 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file swap.c
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

void	p_sa(
			t_ps_context *context
			)
{
	ft_putstr("sa\n");
	ps_sa(context);
}

void	p_sb(
			t_ps_context *context
			)
{
	ft_putstr("sb\n");
	ps_sb(context);
}

void	p_ss(
			t_ps_context *context
			)
{
	ft_putstr("ss\n");
	ps_ss(context);
}
