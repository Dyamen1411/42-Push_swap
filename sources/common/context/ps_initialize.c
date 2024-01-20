/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:38:15 by amassias          #+#    #+#             */
/*   Updated: 2024/01/20 18:10:30 by amassias         ###   ########.fr       */
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

#include <limits.h>
#include <stdlib.h>

/* ************************************************************************** */
/*                                                                            */
/* Helper protoypes                                                           */
/*                                                                            */
/* ************************************************************************** */

static int			_cmp_int(
						int **a,
						int **b
						);

static bool			_parse_and_check_int(
						const char *str,
						int	*res
						);

static bool			_exists(
						t_ps_context *context,
						int value
						);

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
	t_list			*node;
	size_t			i;

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
		if (!_parse_and_check_int(values[i], &context->values[i])
			|| _exists(context, context->values[i]))
			return (ps_cleanup(&context), NULL);
		node = ft_lstnew(&context->values[i]);
		if (node == NULL)
			return (ps_cleanup(&context), NULL);
		ft_lstadd_front(&context->a, node);
	}
	return (_normalize(context));
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

static int	_cmp_int(
				int **a,
				int **b
				)
{
	return ((**a) - (**b));
}

static bool	_parse_and_check_int(
				const char *str,
				int	*res
				)
{
	long	value;
	int		sign;

	value = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		++str;
	}
	if (!ft_isdigit(*str))
		return (false);
	while (ft_isdigit(*str))
	{
		value = 10 * value + (*str++) - '0';
		if (sign * value > INT_MAX || sign * value < INT_MIN)
			return (false);
	}
	while (ft_isspace(*str))
		++str;
	*res = (int) sign * value;
	return (*str == '\0');
}

static bool	_exists(
				t_ps_context *context,
				int value
				)
{
	t_list	*itr;

	itr = context->a;
	while (itr)
	{
		if (*(int *)itr->content == value)
			return (true);
		itr = itr->next;
	}
	return (false);
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
