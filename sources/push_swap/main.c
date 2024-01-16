/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:01:58 by amassias          #+#    #+#             */
/*   Updated: 2024/01/16 15:33:22 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_node(
				void *p
				);

int	main(int argc, char **argv)
{
	t_ps_context	*context;

	(void)argc;
	context = ps_initialize((const char **)(argv + 1));
	if (context == NULL)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), EXIT_FAILURE);
	ft_printf("Success !\n");
	ft_lstiter(context->a, print_node);
	ps_cleanup(&context);
	return (EXIT_SUCCESS);
}

static void	print_node(
				void *p
				)
{
	ft_printf("%d\n", *(int *)p);
}
