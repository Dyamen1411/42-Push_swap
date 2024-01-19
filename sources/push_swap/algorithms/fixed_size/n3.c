/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:05:38 by amassias          #+#    #+#             */
/*   Updated: 2024/01/18 19:13:46 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file n3.c
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
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

void	sort_for_3(
			t_ps_context *context
			)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)context->a->content;
	second = *(int *)context->a->next->content;
	third = *(int *)context->a->next->next->content;
	if (first < second && first < third && second > third)
		(p_sa(context), p_ra(context));
	else if (first < second && first > third && second > third)
		(p_rra(context));
	else if (first > second && first < third && second < third)
		(p_sa(context));
	else if (first > second && first > third && second < third)
		(p_ra(context));
	else if (first > second && first > third && second > third)
		(p_ra(context), p_sa(context));
}
