#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	t_list *head = begin_list;
	int len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}
