/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:01:58 by amassias          #+#    #+#             */
/*   Updated: 2024/01/22 02:04:20 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-01-22
 * @copyright Copyright (c) 2024
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

#include <stdbool.h>

/* ************************************************************************** */
/*                                                                            */
/* Helper protoypes                                                           */
/*                                                                            */
/* ************************************************************************** */

static bool	_is_ok(
				t_ps_context *context,
				t_list *instructions
				);

/* ************************************************************************** */
/*                                                                            */
/* Global variables                                                           */
/*                                                                            */
/* ************************************************************************** */

static t_operator	g_instructions[] = {
[OP_NOP] = do_nothing,
[OP_SA] = ps_sa,
[OP_SB] = ps_sb,
[OP_SS] = ps_ss,
[OP_PA] = ps_pa,
[OP_PB] = ps_pb,
[OP_RA] = ps_ra,
[OP_RB] = ps_rb,
[OP_RR] = ps_rr,
[OP_RRA] = ps_rra,
[OP_RRB] = ps_rrb,
[OP_RRR] = ps_rrr,
};

/* ************************************************************************** */
/*                                                                            */
/* Main                                                                       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_ps_context	*context;
	t_list			*node;
	static t_list	*instructions = NULL;
	char			*instruction;

	context = ps_initialize((const char **)(argv + 1 + (argc ^ argc)));
	if (context == NULL)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), EXIT_FAILURE);
	while (1)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (instruction == NULL)
			break ;
		node = ft_lstnew(instruction);
		if (node == NULL)
			return (free(instruction), ft_lstclear(&instructions, free),
				ps_cleanup(&context), EXIT_FAILURE);
		ft_lstadd_back(&instructions, node);
	}
	if (_is_ok(context, instructions))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (ft_lstclear(&instructions, free), ps_cleanup(&context),
		EXIT_SUCCESS);
}

static t_operator	_get_operator(
						const char *operator
						)
{
	if (ft_strcmp(operator, "sa") == 0)
		return (g_instructions[OP_SA]);
	if (ft_strcmp(operator, "sb") == 0)
		return (g_instructions[OP_SB]);
	if (ft_strcmp(operator, "ss") == 0)
		return (g_instructions[OP_SS]);
	if (ft_strcmp(operator, "pa") == 0)
		return (g_instructions[OP_PA]);
	if (ft_strcmp(operator, "pb") == 0)
		return (g_instructions[OP_PB]);
	if (ft_strcmp(operator, "ra") == 0)
		return (g_instructions[OP_RA]);
	if (ft_strcmp(operator, "rb") == 0)
		return (g_instructions[OP_RB]);
	if (ft_strcmp(operator, "rr") == 0)
		return (g_instructions[OP_RR]);
	if (ft_strcmp(operator, "rra") == 0)
		return (g_instructions[OP_RRA]);
	if (ft_strcmp(operator, "rrb") == 0)
		return (g_instructions[OP_RRB]);
	if (ft_strcmp(operator, "rrs") == 0)
		return (g_instructions[OP_RRR]);
	return (g_instructions[OP_NOP]);
}

static bool	_is_sorted(
				t_list *list
				)
{
	int	last;

	if (list == NULL)
		return (true);
	last = *(int *)list->content;
	list = list->next;
	while (list)
	{
		if (last > *(int *)list->content)
			return (false);
		last = *(int *)list->content;
		list = list->next;
	}
	return (true);
}

static bool	_is_ok(
				t_ps_context *context,
				t_list *instructions
				)
{
	char	*tmp;

	while (instructions)
	{
		tmp = ft_strchr((const char *)instructions->content, '\n');
		if (tmp)
			*tmp = '\0';
		_get_operator(instructions->content)(context);
		instructions = instructions->next;
	}
	return (context->b == NULL && _is_sorted(context->a));
}
