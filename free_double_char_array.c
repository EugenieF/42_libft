#include "libft.h"

void	free_double_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i++] = NULL;
	}
	free(array);
	array = NULL;
}
