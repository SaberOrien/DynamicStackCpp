#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	this->top = 0;
	this->size = 1;
	this->data = (int*)malloc(this->size * sizeof(int));
	if (this->data == NULL) {
		cout << "Error initializing. Aborting" << endl;
		abort();
	}
}

Stack::~Stack()
{
	free(this->data);
}

bool Stack::isEmpty()
{
	return this->top == 0;
}

void Stack::push(int element)
{
	manageMemory();
	this->data[this->top++] = element;
}

void Stack::manageMemory()
{
	if (this->top >= this->size) {
		size_t newSize;
		int* newData;

		if (this->size == 0) {
			newSize = 1;
		}
		else {
			newSize = this->size + GROWTH_FACTOR;
		}

		if (newSize >= (((size_t)-1) - GROWTH_FACTOR) / sizeof(int)) {
			cout << "Not enough memory, aborting.\n" << endl;
			abort();
		}

		newData = (int*)realloc(this->data, newSize * sizeof(int));
		if (!newData) {
			cout << "Unsuccessful expansion. Aborting\n" << endl;
			abort();
		}
		cout << "Stack expansion: " << this->size << " -> " << newSize << endl;
		this->data = newData;
		this->size = newSize;
	}
}

int Stack::pop()
{
	if (isEmpty()) {
		cout << "Popping from an empty stack.\n" << endl;
		abort();
	}
	return this->data[--(this->top)];
}
