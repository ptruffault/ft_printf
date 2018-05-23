#include "../../includes/ft_printf.h"

char 	*ft_arr_to_str(char **arr)
{
	char *head;
	int i;
	int j;
	int size;

	i = 0;
	size = 0;
	head = ft_strnew(0);
	while (arr[i])
	{
		if (!(head = ft_realloc(head, size, size + ft_strlen(arr[i]))))
			return (NULL);
		j = 0;
		while (arr[i][j] != '\0')
			head[size++] = arr[i][j++];
		i++;
	}
	return (head);
}
