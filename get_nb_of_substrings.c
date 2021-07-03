#include "libft.h"

int	get_nb_of_substrings(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
