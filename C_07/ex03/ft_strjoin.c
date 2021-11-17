/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyeon <sooylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:24:21 by sooyeon           #+#    #+#             */
/*   Updated: 2021/10/26 17:24:23 by sooyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int	get_answer_len(int size, char **strs, char *sep)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (i < size)
	{
		length += get_len(strs[i]);
		i ++;
	}
	length += (size - 1) * get_len(sep) + 1;
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i ++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j ++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*answer;

	i = 0;
	answer = malloc(sizeof(char) * get_answer_len(size, strs, sep));
	*answer = 0;
	if (size == 0)
		return (answer);
	if (!answer)
		return (NULL);
	while (i < size)
	{
		ft_strcat(answer, strs[i]);
		if (i < size - 1)
			ft_strcat(answer, sep);
		i ++;
	}
	return (answer);
}	
