#include "Heap.h"

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

Heap::Heap() :capacity(65536), size(0)
{
	arr = new int[capacity];
}

void Heap::push(int n)
{
	if (size == capacity)
	{
		return;
	}
	size++;
	int i = size - 1;

	arr[i] = n;

	// fixing the heap property
	while (i != 0 && arr[(i - 1) / 2] < arr[i])
	{
		swap(&arr[(i - 1) / 2], &arr[i]);
		i = (i - 1) / 2;
	}
}

void Heap::push_min(int n)
{
	if (size == capacity)
	{
		return;
	}
	size++;
	int i = size - 1;

	arr[i] = n;

	// fixing the heap property
	while (i != 0 && arr[(i - 1) / 2] > arr[i])
	{
		swap(&arr[(i - 1) / 2], &arr[i]);
		i = (i - 1) / 2;
	}
}

int Heap::pop()
{
	if (size == 1)
	{
		size--;
		return arr[0];
	}
	if (size > 1)
	{
		int root = arr[0];
		arr[0] = arr[size - 1];
		size--;
		heapify(0);

		return root;
	}
}

int Heap::pop_min()
{
	if (size == 1)
	{
		size--;
		return arr[0];
	}
	if (size > 1)
	{
		int root = arr[0];
		arr[0] = arr[size - 1];
		size--;
		heapify_min(0);

		return root;
	}
}

void Heap::heapify(int n)
{
	// dla MAX
	int l = n;

	// jezeli oba istnieja i oba sa wieksze od parenta
	if (2 * n + 2 < size && arr[2 * n + 1] > arr[n] && arr[2 * n + 2] > arr[n])
	{
		if (arr[2 * n + 1] < arr[2 * n + 2])
		{
			l = 2 * n + 2;
		}
		else if (arr[2 * n + 1] >= arr[2 * n + 2])
		{
			l = 2 * n + 1;
		}
	}

	// jezeli oba istnieja i tylko pierwszy jest wiekszy od parenta
	if (2 * n + 2 < size && arr[2 * n + 1] > arr[n] && arr[2 * n + 2] <= arr[n])
	{
		l = 2 * n + 1;
	}

	// jezeli oba istnieja i tylko drugi jest wiekszy od parenta
	if (2 * n + 2 < size && arr[2 * n + 2] > arr[n] && arr[2 * n + 1] <= arr[n])
	{
		l = 2 * n + 2;
	}

	// jezeli istnieje tylko lewy i jest wieszy od parenta
	if (2 * n + 1 < size && 2 * n + 2 >= size && arr[2 * n + 1] > arr[n])
	{
		l = 2 * n + 1;
	}

	// jezeli istnieje tylko lewy i jest rowny badz mniejszy od parenta
	// lub
	// parent nie ma zadnego dziecka (ani lewego ani prawego)
	// lub
	// parent ma 2 dzieci ale zaden nie jest wiekszy od niego
	// to
	// l sie nie zmienia, i swap, i rekurencja sie nie wywoluja i funkcja sie konczy
	if (l != n)
	{
		swap(&arr[n], &arr[l]);
		heapify(l);
	}
}

void Heap::heapify_min(int n)
{
	// dla MIN
	int l = n;

	// jezeli oba istnieja i oba sa mniejsze od parenta
	if (2 * n + 2 < size && arr[2 * n + 1] < arr[n] && arr[2 * n + 2] < arr[n])
	{
		if (arr[2 * n + 1] > arr[2 * n + 2])
		{
			l = 2 * n + 2;
		}
		else if (arr[2 * n + 1] <= arr[2 * n + 2])
		{
			l = 2 * n + 1;
		}
	}

	// jezeli oba istnieja i tylko pierwszy jest mniejszy od parenta
	if (2 * n + 2 < size && arr[2 * n + 1] < arr[n] && arr[2 * n + 2] >= arr[n])
	{
		l = 2 * n + 1;
	}

	// jezeli oba istnieja i tylko drugi jest mniejszy od parenta
	if (2 * n + 2 < size && arr[2 * n + 2] < arr[n] && arr[2 * n + 1] >= arr[n])
	{
		l = 2 * n + 2;
	}

	// jezeli istnieje tylko lewy i jest mniejszy od parenta
	if (2 * n + 1 < size && 2 * n + 2 >= size && arr[2 * n + 1] < arr[n])
	{
		l = 2 * n + 1;
	}

	// jezeli istnieje tylko lewy i jest rowny badz wiekszy od parenta
	// lub
	// parent nie ma zadnego dziecka (ani lewego ani prawego)
	// lub
	// parent ma 2 dzieci ale zaden nie jest mniejszy od niego
	// to
	// l sie nie zmienia, i swap, i rekurencja sie nie wywoluja i funkcja sie konczy
	if (l != n)
	{
		swap(&arr[n], &arr[l]);
		heapify_min(l);
	}
}

void Heap::write_elements()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

bool Heap::is_empty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

void Heap::add_normally(int* arr_number, int times)
{
	for (int i = 0; i < times; i++)
	{
		arr[i] = arr_number[i];
		size++;
	}
}

int Heap::get_size()
{
	return size;
}