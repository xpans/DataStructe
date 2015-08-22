#include "SinglyList.h"

template<typename T>
class LinkedStack
{
public:
	LinkedStack(){};
	~LinkedStack(){};

	bool empty();
	void push(T x);//λ��i=0Ϊջ��
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
	throw logic_error("��ջ������ִ�г�ջ����");
}

template<typename T>
T LinkedStack<T>::get()
{
	if (!empty())
	{
		return this->list.get(0);
	}
	throw logic_error("��ջ�����ܻ��ջ��Ԫ��");
}
