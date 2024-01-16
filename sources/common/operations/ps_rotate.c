/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:27:29 by amassias          #+#    #+#             */
/*   Updated: 2024/01/16 14:32:02 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ps_rotate.c
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

static void	_rotate(
				t_list **stack
				);

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

void	ps_ra(
			t_ps_context *context
			)
{
	_rotate(&context->a);
}

void	ps_rb(
			t_ps_context *context
			)
{
	_rotate(&context->b);
}

void	ps_rr(
			t_ps_context *context
			)
{
	_rotate(&context->a);
	_rotate(&context->b);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

static void	_rotate(
				t_list **stack
				)
{
	t_list	*head;

	if (*stack == NULL)
		return ;
	head = *stack;
	head->next = NULL;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, head);
}
