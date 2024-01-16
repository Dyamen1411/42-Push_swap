/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:32:31 by amassias          #+#    #+#             */
/*   Updated: 2024/01/16 15:04:49 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ps_reverse_rotate.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-01-16
 * @copyright Copyright (c) 2024
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/* Helper protoypes                                                           */
/*                                                                            */
/* ************************************************************************** */

static void	_reverse_rotate(
				t_list **stack
				);

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

void	ps_rra(
			t_ps_context *context
			)
{
	_reverse_rotate(&context->a);
}

void	ps_rrb(
			t_ps_context *context
			)
{
	_reverse_rotate(&context->b);
}

void	ps_rrr(
			t_ps_context *context
			)
{
	_reverse_rotate(&context->a);
	_reverse_rotate(&context->b);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

static void	_reverse_rotate(
				t_list **stack
				)
{
	t_list	**itr;

	if (*stack == NULL)
		return ;
	itr = stack;
	while ((*itr)->next)
		itr = &(*itr)->next;
	(*itr)->next = *stack;
	*stack = *itr;
	*itr = NULL;
}
