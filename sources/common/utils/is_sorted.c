/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:42:17 by amassias          #+#    #+#             */
/*   Updated: 2024/01/22 02:44:03 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_sorted.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-01-22
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

bool	is_sorted(
			t_list *list
			)
{
	int	v;

	if (list == NULL)
		return (true);
	v = *(int *)list->content;
	list = list->next;
	while (list)
	{
		if (v > *(int *)list->content)
			return (false);
		v = *(int *)list->content;
		list = list->next;
	}
	return (true);
}
