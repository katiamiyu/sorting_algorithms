#include "sort.h"
/**
 * selection_sort - sorts an array using selection
 * @array: list of integers
 * @size: number of elements
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, m = 0;
	int temp = 0;

	if (!array || size < 2)
		return;
	for (x = 0; x < size; x++)
	{
		m = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[m] > array[y])
			{
				m = y;
			}
		}

		if (x != m)
		{
			temp = array[x];
			array[x] = array[m];
			array[m] = temp;
		}

		print_array(array, size);

	}
}
