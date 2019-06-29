#ifndef _STACK_H_
#define _STACK_H_

struct customer
{
	char fullname[35];
	double payment;
};

typedef customer Item;

// ADT
class Stack
{
private:
	enum {MAX = 10};		// 在类内定义了一个字符常量
	Item items[MAX];		// 栈的大小
	int top;				// 栈顶

public:
	Stack();							// 创建一个空栈
	bool isempty() const;
	bool isfull() const;
	bool push(const Item &item);
	bool pop(Item &item);
};

#endif // !_STACK_H_

