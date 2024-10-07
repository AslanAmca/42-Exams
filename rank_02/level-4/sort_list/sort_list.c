#include "list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *current = lst;
	t_list *next = 0;

	while (current != 0)
	{
		next = current->next;
		while (next != 0)
		{
			if ((*cmp)(current->data, next->data) == 0)
			{
				int temp = current->data;
				current->data = next->data;
				next->data = temp;
			}
			next = next->next;
		}
		current = current->next;
	}
	return lst;
}
