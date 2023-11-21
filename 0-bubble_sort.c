#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: integer 1
 * @b: integer 2
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort data two by two
 * @array: array of integer
 * @size: size of array
 * Description: print array after each step
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx;
	size_t len = size;
	bool bub = false;

	if (array == NULL || size < 2)
		return;
	while (bub == false)
	{
		bub = true;
		for (idx = 0; idx < len - 1; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
				swap_ints(array + idx, array + idx + 1);
				print_array(array, size);
				bub = false;
			}
		}
		len--;
	}
}
