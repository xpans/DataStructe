#include "Node.h"

template<typename T>
class LinkedQueue
{
public:
	LinkedQueue();
	~LinkedQueue(){};
	bool empty();
	void enqueue(T x);
	T dequeue();

private:
	Node<T>*front,*rear;

};

template<typename T>
LinkedQueue<T>::LinkedQueue()
{
	this->front=this->rear=NULL;
}

template<typename T>
bool LinkedQueue<T>::empty()
{
	return this->front==NULL&&this->rear==NULL;
}

template<typename T>
void LinkedQueue<T>::enqueue(T x)
{
	Node<T>*q=new Node<T>(x);
	if (empty())//首先判断队列是否为空，为空则应将front从null改为指向q
	{
		this->front=q;
	}
	else
	{
		this->rear->next=q;//如果不为空将数据放入队尾
	}
	this->rear=q;//无论怎样都应将队尾指针指向最后即q
}

template<typename T>
T LinkedQueue<T>::dequeue()
{
	if (!empty())
	{
		Node<T>*q=this->front;
		T e=q->data;
		this->front=this->front->next;
		//***注意最后一个结点出队列时，应使front和next指针一致为null
		if (front==NULL)//最后一个结点被移除队列
		{
			this->rear=NULL;
		}
		delete q;
		return e;
	}
	throw logic_error("空队列，无法出队列");
}