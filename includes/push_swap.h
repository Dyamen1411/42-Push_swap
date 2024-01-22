/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:44:21 by amassias          #+#    #+#             */
/*   Updated: 2024/01/22 01:32:26 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.h
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2024-01-16
 * @copyright Copyright (c) 2024
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

# include <libft.h>

/* ************************************************************************** */
/*                                                                            */
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

# define OP_NOP 0x0
# define OP_SA 0x1
# define OP_SB 0x2
# define OP_SS 0x3
# define OP_PA 0x4
# define OP_PB 0x5
# define OP_RA 0x6
# define OP_RB 0x7
# define OP_RR 0x8
# define OP_RRA 0x9
# define OP_RRB 0xA
# define OP_RRR 0xB

/* ************************************************************************** */
/*                                                                            */
/* Structures                                                                 */
/*                                                                            */
/* ************************************************************************** */

struct	s_ps_context
{
	t_list	*a;
	t_list	*b;
	int		*values;
	size_t	count;
};

/* ************************************************************************** */
/*                                                                            */
/* Types                                                                      */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_ps_context	t_ps_context;

typedef void				(*t_operator)(t_ps_context *);

/* ************************************************************************** */
/*                                                                            */
/* Header protoypes                                                           */
/*                                                                            */
/* ************************************************************************** */

t_ps_context				*ps_initialize(
								const char **values
								);

void						ps_sa(
								t_ps_context *context
								);

void						ps_sb(
								t_ps_context *context
								);

void						ps_ss(
								t_ps_context *context
								);

void						ps_pa(
								t_ps_context *context
								);

void						ps_pb(
								t_ps_context *context
								);

void						ps_ra(
								t_ps_context *context
								);

void						ps_rb(
								t_ps_context *context
								);

void						ps_rr(
								t_ps_context *context
								);

void						ps_rra(
								t_ps_context *context
								);

void						ps_rrb(
								t_ps_context *context
								);

void						ps_rrr(
								t_ps_context *context
								);

void						ps_cleanup(
								t_ps_context **context_ptr
								);

#endif