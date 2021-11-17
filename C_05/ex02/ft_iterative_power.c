/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyeon <sooylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:20:58 by sooyeon           #+#    #+#             */
/*   Updated: 2021/10/24 20:49:38 by sooylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	answer;

	answer = 1;
	if (power < 0 || (nb == 0 && power > 0))
		return (0);
	if (power == 0 || (power == 0 && nb == 0))
		return (1);
	while (power > 0)
	{
		answer *= nb;
		power --;
	}
	return (answer);
}
