#pragma once
#pragma warning(disable:4715)
#include <iostream>

class Heap
{
private:
	int* arr;
	int capacity, size;
public:
	Heap();
	void push(int n);
	void push_min(int n);

	int pop();
	int pop_min();

	void heapify(int n);
	void heapify_min(int n);

	void write_elements();
	bool is_empty();

	void add_normally(int* arr_number, int times);
	int get_size();
};