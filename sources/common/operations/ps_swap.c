/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:20:16 by amassias          #+#    #+#             */
/*   Updated: 2024/01/16 14:26:24 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ps_swap.c
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

static void	_swap(
				t_list **list
				);

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

void	ps_sa(
			t_ps_context *context
			)
{
	_swap(&context->a);
}

void	ps_sb(
			t_ps_context *context
			)
{
	_swap(&context->b);
}

void	ps_ss(
			t_ps_context *context
			)
{
	_swap(&context->a);
	_swap(&context->b);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

static void	_swap(
				t_list **stack
				)
{
	t_list	*first;
	t_list	*second;
	t_list	*rest;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	rest = second->next;
	first->next = rest;
	second->next = first;
	*stack = second;
}
