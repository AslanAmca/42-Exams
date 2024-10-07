#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current = *begin_list;
	t_list *next = NULL;

	while (current != NULL)
	{
		next = current->next;

		if ((*cmp)(current->data, data_ref) == 0)
			free(current);

		current = next;
	}
}
