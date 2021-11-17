/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyeon <sooylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:31:07 by sooyeon           #+#    #+#             */
/*   Updated: 2021/10/27 18:46:28 by sooylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;
	int		length;

	i = 0;
	length = get_length(str);
	dest = malloc(sizeof(char) * (length + 1));
	while (str[i])
	{
		dest[i] = str[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int argc, char **argv)
{
	int			i;
	t_stock_str	*answer;

	i = 0;
	answer = malloc(sizeof(t_stock_str) * (argc + 1));
	if (!answer)
		return (0);
	while (i < argc)
	{
		answer[i].size = get_length(argv[i]);
		answer[i].str = argv[i];
		answer[i].copy = ft_strdup(argv[i]);
		i ++;
	}
	answer[i].str = 0;
	return (answer);
}
