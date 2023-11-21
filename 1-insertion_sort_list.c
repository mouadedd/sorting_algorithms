#include "sort.h"

/**
 *insertion_sort_list - sort a dobly linked list
 *@list: double to pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node_ins, *next_ins;

	if (list == NULL || *list == NULL)
		return;
	node_ins = (*list)->next;
	while (node_ins != NULL)
	{
		next_ins = node_ins->next;
		while (node_ins->prev != NULL && node_ins->prev->n > node_ins->n)
		{
			node_ins->prev->next = node_ins->next;
			if (node_ins->next != NULL)
				node_ins->next->prev = node_ins->prev;
			node_ins->next = node_ins->prev;
			node_ins->prev = node_ins->next->prev;
			node_ins->next->prev = node_ins;
			if (node_ins->prev == NULL)
				*list = node_ins;
			else
				node_ins->prev->next = node_ins;
			print_list(*list);
		}
		node_ins = next_ins;
	}
}
