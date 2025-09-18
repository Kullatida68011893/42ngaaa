
#include "libft.h"
#include <stdlib.h>

static int	get_num_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++; 
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	ln;
	int		len;
	
	ln = n;
	len = get_num_len(ln);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	str[len] = '\0';
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	if (ln == 0)
	{
		str[0] = '0';
		return (str);
	}

	while (ln > 0)
	{
		len--;
		str[len] = (ln % 10) + '0';
		ln /= 10;
	}

	return (str);
}