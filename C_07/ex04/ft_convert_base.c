/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyeon <sooylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:34:44 by sooyeon           #+#    #+#             */
/*   Updated: 2021/10/26 17:35:17 by sooyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_length(char *str);
int	check_error(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_nbrlen(long n, char *base)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= get_length(base))
	{
		n /= get_length(base);
		len++;
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base, char *res, int i)
{
	int		len_base;
	long	n;

	n = nbr;
	len_base = get_length(base);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	if (n < len_base)
		res[i] = base[n];
	else
	{
		ft_putnbr_base(n / len_base, base, res, i - 1);
		ft_putnbr_base(n % len_base, base, res, i);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*answer;
	int		n;

	if (!nbr || !check_error(base_from) || !check_error(base_to))
		return (0);
	n = ft_atoi_base(nbr, base_from);
	answer = malloc(sizeof(char) * (ft_nbrlen(n, base_to) + 1));
	ft_putnbr_base(n, base_to, answer, ft_nbrlen(n, base_to));
	answer[(ft_nbrlen(n, base_to) + 1)] = '\0';
	return (answer);
}
