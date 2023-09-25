#include "sort.h"
int *lumota(int *arr, int low, int high, size_t size);
/**
 * quick_sort - sort algorithm implementation
 * @array: array of integer
 * @size: numbrr of integer
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	high = size - 1;
	low = 0;
	lumota(array, low, high, size);
	print_array(array, size);

}
/**
 * lumota - lumota quicksort style
 * @arr: array of int
 * @low: lowest end of value
 * @high: high end
 * Return: sorted array
 */
int *lumota(int *arr, int low, int high, size_t size)
{
	if (low >= high)
		return (arr);
	else {

	int p = arr[high];
	int i,j;
	int temp;

	i = j = low;

	for (; i < high; i++)
	{
		if (arr[i] <= p)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j++;
		}
	}
	temp = arr[high];
	arr[high] = arr[j];
	arr[j] = temp;

	print_array(arr, size);
	lumota(arr, low, j - 1, size);
	lumota(arr, j + 1, high, size);
	return (arr);
	}
}

