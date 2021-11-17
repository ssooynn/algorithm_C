/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyeon <sooylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:35:25 by sooyeon           #+#    #+#             */
/*   Updated: 2021/10/26 17:35:26 by sooyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_length(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length ++;
	return (length);
}

char	*get_base(char *base, char *to_find)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == *to_find)
			return (&base[i]);
		i++;
	}
	return (0);
}

int	check_error(char *base)
{
	int		check_i;
	char	*check;

	check = base;
	if (*base == 0 || *(base + 1) == 0)
		return (0);
	while (*check)
	{
		if (*check == '+' || *check == '-' || *check < 33)
			return (0);
		check_i = 1;
		while (*(check + check_i))
		{
			if (*(check + check_i) == *(check))
				return (0);
			check_i++;
		}
		check++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (check_error(base))
	{
		i = 0;
		while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		while (get_base(base, &str[i]))
		{
			result *= get_length(base);
			result += get_base(base, &str[i]) - base;
			i++;
		}
	}
	return (sign * result);
}
