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
 * lomuto_part - Order by lomuto partition scheme
 * @array: array of integers.
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 * Return: partition index.
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_ints(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto - Implement the quicksort
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void lomuto(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_part(array, size, left, right);
		lomuto(array, size, left, part - 1);
		lomuto(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers
 * @array: array of integer
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto(array, size, 0, size - 1);
}
