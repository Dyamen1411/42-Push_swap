/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:40:47 by amassias          #+#    #+#             */
/*   Updated: 2024/01/22 01:31:16 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file utils.h
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-01-16
 * @copyright Copyright (c) 2024
 */

#ifndef UTILS_H
# define UTILS_H

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

# include <libft.h>
# include <stdbool.h>

/* ************************************************************************** */
/*                                                                            */
/* Header protoypes                                                           */
/*                                                                            */
/* ************************************************************************** */

bool	is_string_integer(
			const char *str
			);

void	do_nothing(
			t_ps_context *context
			);

#endif