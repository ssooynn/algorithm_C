#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int	is_valid(char *base)
{
	int	i;
	int 	j;
	
	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '-')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j ++;
		}
		i ++;	
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;
	int	changed_nbr[100];
	int i;

	i = 0;
	base_length = 0;
	if (is_valid(base))
	{
		if (nbr < 0 )
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[base_length])
			base_length ++;
		while (nbr)
		{
			changed_nbr[i] = nbr % base_length;
			nbr /= base_length;
			i ++;
		}
		while (i-- > 0)
			ft_putchar(base[changed_nbr[i]]);
		
}
