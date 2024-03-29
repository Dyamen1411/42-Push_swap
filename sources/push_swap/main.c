/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:01:58 by amassias          #+#    #+#             */
/*   Updated: 2024/01/22 02:46:20 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-01-16
 * @copyright Copyright (c) 2024
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "utils.h"

#include <limits.h>
#include <stdbool.h>

/* ************************************************************************** */
/*                                                                            */
/* Main                                                                       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_ps_context	*context;

	(void)argc;
	context = ps_initialize((const char **)(argv + 1));
	if (context == NULL)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), EXIT_FAILURE);
	if (context->count < 2 || is_sorted(context->a))
		;
	else if (context->count == 2)
		sort_for_2(context);
	else if (context->count == 3)
		sort_for_3(context);
	else if (context->count == 4)
		sort_for_4(context);
	else if (context->count == 5)
		sort_for_5(context);
	else
		radix_sort(context);
	return (ps_cleanup(&context), EXIT_SUCCESS);
}
