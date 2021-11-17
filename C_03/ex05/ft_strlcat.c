int	get_length(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length ++;
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	length;
	unsigned int	result;

	length = get_length(dest);
	result = get_length(src);
	i = 0;
	j = length;
	while ((src[i] != '\0') && i < (size - length - 1))
	{
		dest[j] = src[i];
		i ++;
		j ++;
	}
	dest[j] = '\0';
	if (size < length + 1)
		result += size;
	else
		result += length;
	return (result);
}
