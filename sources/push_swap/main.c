/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:01:58 by amassias          #+#    #+#             */
/*   Updated: 2024/01/18 23:28:55 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <limits.h>
#include <stdbool.h>

int	main(int argc, char **argv)
{
	t_ps_context	*context;

	(void)argc;
	context = ps_initialize((const char **)(argv + 1));
	if (context == NULL)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), EXIT_FAILURE);
	if (context->count < 2)
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
