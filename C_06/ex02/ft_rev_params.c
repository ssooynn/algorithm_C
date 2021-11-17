/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooylee <sooylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:36:57 by sooylee           #+#    #+#             */
/*   Updated: 2021/10/24 21:36:59 by sooylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
	write(1, &"\n", 1);
}

int	main(int argc, char **argv)
{
	argc --;
	while (0 < argc)
	{
		print_argv(argv[argc]);
		argc --;
	}
}
