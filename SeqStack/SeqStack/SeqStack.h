#include "SeqList.h"

template<typename T>
class SeqStack
{
public:
	SeqStack(){};
	~SeqStack(){};
	bool empty();
	void push(T x);
	T pop();
	T get();

private:
	SeqList<T> list;
};

template<typename T>
bool SeqStack<T>::empty()
{
	return this->list.empty();
}

template<typename T>
void SeqStack<T>::push(T x)
{
	this->list.insert(x);
}

template<typename T>
T SeqStack<T>::pop()
{
	if (!this->empty())
	{
		return this->list.remove(this->list.count()-1);
	}
	throw logic_error("空栈，不能执行出栈操作");
}

template<typename T>
T SeqStack<T>::get()
{
	if (!empty())
	{
		return this->list[this->list.count()-1];
	}
	throw logic_error("空栈，不能获得栈顶元素");
}