#include "sort.h"
/**
 *selection_sort - sorts array in ascending order
 *@array: array to sort
 *@size: array length
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, x;
	int rteb;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		x = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[x])
				x = j;

		}
		if (i != x)
		{
			rteb = array[i];
			array[i] = array[x];
			array[x] = rteb;
			print_array(array, size);
		}
	}
}
