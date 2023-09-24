#include "sort.h"
/**
 * bubble_sort - sorts a given array of integers.
 * @array: array of integers.
 * @size: total of array elements.
 * Return: void.
 */
void bubble_sort(int *array, size_t size)
{
	size_t counter, counter2;
	int temp, sorted;

	if (array && size > 0)
	{
		for (counter = 0; counter < size; counter++)
		{
			sorted = 1;
			for (counter2 = 1; counter2 < size - counter; counter2++)
			{
				if (array[counter2] < array[counter2 - 1])
				{
					temp = array[counter2];
					array[counter2] = array[counter2 - 1];
					array[counter2 - 1] = temp;
					print_array(array, size);
					sorted = 0;
				}
			}
			if (sorted == 1)
				return;
		}
	}
	else
		return;
}
