#include "Heap.h"

int main()
{
	Heap heap;
	char n;
	bool is_min = false;
	bool flag = false;
	while (std::cin >> n)
	{
		if (n == '+')
		{
			if (is_min == false)
			{
				int temp;
				std::cin >> temp;
				heap.push(temp);
			}
			else
			{
				int temp;
				std::cin >> temp;
				heap.push_min(temp);
			}
		}
		else if (n == '-')
		{
			if (is_min == false)
			{
				std::cout << heap.pop();
				std::cout << std::endl;
			}
			else
			{
				std::cout << heap.pop_min();
				std::cout << std::endl;
			}
		}
		else if (n == 'p')
		{
			heap.write_elements();
			std::cout << std::endl;
		}
		else if (n == 'r')
		{
			while (!heap.is_empty())
			{
				heap.pop();
			}
			int temp;
			std::cin >> temp;
			int* help = new int[temp];
			for (int i = 0; i < temp; i++)
			{
				std::cin >> help[i];
			}
			heap.add_normally(help, temp);
			if (is_min == false)
			{
				int x = (heap.get_size() / 2) - 1;
				for (int i = x; i >= 0; i--)
				{
					heap.heapify(i);
				}
			}
			else
			{
				int x = (heap.get_size() / 2) - 1;
				for (int i = x; i >= 0; i--)
				{
					heap.heapify_min(i);
				}
			}
		}
		else if (n == 's')
		{
			if (is_min == false)
			{
				is_min = true;
				int x = (heap.get_size() / 2) - 1;
				for (int i = x; i >= 0; i--)
				{
					heap.heapify_min(i);
				}
			}
			else
			{
				is_min = false;
				int x = (heap.get_size() / 2) - 1;
				for (int i = x; i >= 0; i--)
				{
					heap.heapify(i);
				}
			}
		}
		else if (n == 'q')
		{
			break;
		}
	}
	std::cin.ignore();
	std::cin.ignore();
}