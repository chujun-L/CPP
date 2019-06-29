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
	enum {MAX = 10};		// �����ڶ�����һ���ַ�����
	Item items[MAX];		// ջ�Ĵ�С
	int top;				// ջ��

public:
	Stack();							// ����һ����ջ
	bool isempty() const;
	bool isfull() const;
	bool push(const Item &item);
	bool pop(Item &item);
};

#endif // !_STACK_H_

