#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int size = 0;
	while (begin_list != 0)
	{
		size++;
		begin_list = begin_list->next;
	}
	return size;
}
