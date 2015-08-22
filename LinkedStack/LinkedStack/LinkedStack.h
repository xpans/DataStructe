#include "SinglyList.h"

template<typename T>
class LinkedStack
{
public:
	LinkedStack(){};
	~LinkedStack(){};

	bool empty();
	void push(T x);//位置i=0为栈顶
	T pop();
	T get();
private:
	SinglyList<T> list;

};

template<typename T>
bool LinkedStack<T>::empty()
{
	return this->list.empty();
}

template<typename T>
void LinkedStack<T>::push(T x)
{
	this->list.insert(0,x);
}

template<typename T>
T LinkedStack<T>::pop()
{
	if (!empty())
	{
		return this->list.remove(0);
	}
	throw logic_error("空栈，不能执行出栈操作");
}

template<typename T>
T LinkedStack<T>::get()
{
	if (!empty())
	{
		return this->list.get(0);
	}
	throw logic_error("空栈，不能获得栈顶元素");
}
