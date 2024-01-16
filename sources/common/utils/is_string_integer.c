/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:43:15 by amassias          #+#    #+#             */
/*   Updated: 2024/01/16 14:52:51 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_string_integer.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-01-16
 * @copyright Copyright (c) 2024
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdbool.h>

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

bool	is_string_integer(
			const char *str
			)
{
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
		++str;
	if (!ft_isdigit(*str))
		return (false);
	++str;
	while (ft_isdigit(*str))
		++str;
	while (ft_isspace(*str))
		++str;
	return (*str == '\0');
}
