#include "sort.h"
void reset_list(listint_t *list);
/**
 * insertion_sort_list - sort items of  linked list
 * @list: linklist pointer
 * Return void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	if (!list || !(*list)->next)
		return;

	if (*list)
	{
		reset_list(*list);

	}

	current = (*list)->next;
	while (current)
	{
		temp = current->prev;
		while (temp && temp->n > current->n)
		{
			if (temp->prev)
				temp->prev->next = current;
			if (current->next)
				current->next->prev = temp;
			temp->next = current->next;
			current->prev = temp->prev;

			current->next = temp;
			temp->prev = current;
			if (current->prev == NULL)
				*list = current;
			temp = current->prev;
			print_list(*list);
		}
		current = current->next;
	}

}
/**
 * reset_list - go to begining of list
 * @list: list to traverse
 * Return: void
 */
void reset_list(listint_t *list)
{
	if (list)
	{
		while (list->prev)
		{
			list = list->prev;
		}
	}
}
