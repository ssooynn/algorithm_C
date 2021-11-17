#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int ft_atoi(char *str);

int main()
{
	char s1[11];
	char s2[11];
	printf("%d", ft_atoi("123123"));
	printf("%s", "\n");
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d", ft_atoi("2147483647"));

}
