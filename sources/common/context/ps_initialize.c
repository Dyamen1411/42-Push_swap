/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:38:15 by amassias          #+#    #+#             */
/*   Updated: 2024/01/16 18:14:30 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ps_initialize.c
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
#include "utils.h"

#include <stdlib.h>

/* ************************************************************************** */
/*                                                                            */
/* Helper protoypes                                                           */
/*                                                                            */
/* ************************************************************************** */

static t_ps_context	*_normalize(
						t_ps_context *context
						);

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

t_ps_context	*ps_initialize(
					const char **values
					)
{
	t_ps_context	*context;
	size_t			i;
	t_list			*node;

	context = (t_ps_context *)ft_calloc(1, sizeof(t_ps_context));
	if (context == NULL)
		return (NULL);
	while (values[context->count])
		++context->count;
	context->values = (int *)malloc(context->count * sizeof(int));
	if (context->values == NULL)
		return (ps_cleanup(&context), NULL);
	i = context->count;
	while (i-- > 0)
	{
		if (!is_string_integer(values[i]))
			return (ps_cleanup(&context), NULL);
		context->values[i] = ft_atoi(values[i]);
		node = ft_lstnew(&context->values[i]);
		if (node == NULL)
			return (ps_cleanup(&context), NULL);
		ft_lstadd_front(&context->a, node);
	}
	return (_normalize(context));
}

static int	_cmp_int(
				int **a,
				int **b
				)
{
	return ((**a) - (**b));
}

static t_ps_context	*_normalize(
						t_ps_context *context
						)
{
	int		**tmp;
	size_t	i;

	if (context->count == 0)
		return (context);
	tmp = (int **)malloc(context->count * sizeof(int *));
	if (tmp == NULL)
		return (ps_cleanup(&context), NULL);
	i = 0;
	while (i < context->count)
	{
		tmp[i] = &context->values[i];
		++i;
	}
	ft_qsort(tmp, context->count, sizeof(int *), (t_comparator) _cmp_int);
	i = 0;
	while (i < context->count)
	{
		*(tmp[i]) = i;
		++i;
	}
	free(tmp);
	return (context);
}
