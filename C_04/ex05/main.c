#include <stdio.h>
int	ft_atoi_base(char *str, char *base);

int main()
{
	printf("%d", ft_atoi_base("a", "0123456789abcdef"));
}
