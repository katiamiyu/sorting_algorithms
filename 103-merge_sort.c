#include "sort.h"

void merge(int *array, int left, int middle, int right);
void split(int *array, int left, int right);
/**
 * merge_sort - sort an array of integers using merge sort
 * @array: The array two be sorted
 * @size: size of the array
 *
 * Retrun: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int len = size;

	if (!array || len < 2)
		return;
	split(array, 0, len - 1);
}

void split(int *array, int left, int right)
{
	int middle = 0;

	if (left < right)
	{
		middle = (left + right) / 2;

		/*Sort left and right halves*/
		split(array, left, middle);
		split(array, middle + 1, right);

		merge(array, left, middle, right);
	}
}

void merge(int *array, int left, int middle, int right)
{
	int i = 0, j = 0, k = 0, *arrayTemp = NULL;
	int num = middle - left + 1;
	int num2 = right - middle;

	arrayTemp = malloc(sizeof(int) * (num + num2));
	if (!arrayTemp)
		return;

	/*Copy the data to a temp array leftArr and rightArr*/
	for (; i < num; i++)
		arrayTemp[i] = array[left + i];
	for (j = 0; j < num2; j++)
		arrayTemp[num + j] = array[middle + 1 + j];

	printf("Merging...\n[left]: ");
	print_array(arrayTemp, num);
	printf("[right]: ");
	print_array(arrayTemp + num, num2);
	/*Place vallue in right order in the array*/
	i = 0;
	j = num;
	k = left;
	while (i < num && j < num + num2)
	{
		if (arrayTemp[i] <= arrayTemp[j])
			array[k++] = arrayTemp[i++];
		else
			array[k++] = arrayTemp[j++];
	}

	while (i < num)
		array[k++] = arrayTemp[i++];

	while (j < num + num2)
		array[k++] = arrayTemp[j++];

	printf("[Done]: ");
	print_array(array + left, num + num2);

	free(arrayTemp);
}
