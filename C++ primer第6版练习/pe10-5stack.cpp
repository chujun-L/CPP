#include "pe10-5stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	top = 0;	
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const Item &item)
{
	if (isfull())
	{
		cout << "stack is full" << endl;
		return false;
	}
	else
	{
		items[top++] = item;
		return true;
	}
}

bool Stack::pop(Item &item)
{
	if (isempty())
	{
		cout << "stack is empty" << endl;
		return false;
	}
	else
	{
		item = items[--top];
		return true;
	}
}
