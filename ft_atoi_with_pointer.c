#include "libft.h"

long	ft_atoi_with_pointer(char **str)
{
	unsigned long	res;
	int				sign;

	sign = 1;
	res = 0;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		res = res * 10 + **str - '0';
		(*str)++;
	}
	return (sign * res);
}
