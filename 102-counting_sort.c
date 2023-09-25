#include "sort.h"

/**
 * counting_sort - Sort an array using count sort
 * @array: array of integer
 * @size: size lenght
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *result = NULL, *count = NULL;
	int i = 0, max = 0, len = 0;

	if (!array || size < 2)
		return;
	len = size;
	max = array[0];
	for (i = 1; i < len; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));/*create mem*/
	if (!count)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < len; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	result = malloc(sizeof(int) * len);/*create mem*/
	if (result == NULL)
	{
		free(count);
		return;
	}
	for (i = len - 1; i >= 0; i--)
	{
		result[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < len; i++)
		array[i] = result[i];
	free(result);
	free(count);
}
