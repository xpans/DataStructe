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
	if (empty())//�����ж϶����Ƿ�Ϊ�գ�Ϊ����Ӧ��front��null��Ϊָ��q
	{
		this->front=q;
	}
	else
	{
		this->rear->next=q;//�����Ϊ�ս����ݷ����β
	}
	this->rear=q;//����������Ӧ����βָ��ָ�����q
}

template<typename T>
T LinkedQueue<T>::dequeue()
{
	if (!empty())
	{
		Node<T>*q=this->front;
		T e=q->data;
		this->front=this->front->next;
		//***ע�����һ����������ʱ��Ӧʹfront��nextָ��һ��Ϊnull
		if (front==NULL)//���һ����㱻�Ƴ�����
		{
			this->rear=NULL;
		}
		delete q;
		return e;
	}
	throw logic_error("�ն��У��޷�������");
}