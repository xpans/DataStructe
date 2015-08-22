#include <iostream>
#include "DoubleNode.h"

using namespace std;

template<typename T>
class CirDoubleList
{
public:
	DoubleNode<T>*head;

	CirDoubleList();
	CirDoubleList(T values[],int n);//���캯������
	~CirDoubleList();

	//�ж������Ƿ�Ϊ��
	bool empty();
	//�����㣬��iλ�ò�������x�������ز���λ��
	DoubleNode<T>* insert(T x,int i);
	DoubleNode<T>* insert(T x);//�ڱ�β������X
	friend ostream& operator<<<>(ostream& out,CirDoubleList<T> &list);
	T remove(int i);


private:

};

template<typename T>
//���캯�����������⣬ǰ���ͺ�����ָ��ͷ��㣬Ϊ��˫������
CirDoubleList<T>::CirDoubleList()
{
	this->head=new DoubleNode<T>();
	this->head->prev=this->head;
	this->head->next=this->head;
}
template<typename T>
CirDoubleList<T>::CirDoubleList(T values[],int n)
{
	this->head=new DoubleNode<T>();
	this->head->prev=this->head;
	this->head->next=this->head;
	for (int i=0;i<n;i++)
	{
		this->insert(values[i],i);
	}
#if 0
	this->head=new DoubleNode<T>();
	this->head->prev=this->head;
	this->head->next=this->head;
	DoubleNode<T>* p=this->head;
	for (int i=0;i<n;i++)
	{
		DoubleNode<T>*q=new DoubleNode<T>(values[i],p,p->next);
		p->next->prev=q;
		p->next=q;
		p=p->next;
	}
#endif
	
}

template<typename T>
CirDoubleList<T>::~CirDoubleList()
{
}

//�ж������Ƿ�Ϊ��
template<typename T>
bool CirDoubleList<T>::empty()
{
	return this->head->next==this->head;
}
//���±�iλ�ò�����x,�����ص�ַ
template<typename T>
DoubleNode<T>* CirDoubleList<T>::insert(T x,int i)
{
	DoubleNode<T>* p=this->head;
	//�ҵ�����λ�õ�ǰһ���
	for (int j=0;p->next!=head&&j<i;j++)
	{
		p=p->next;//����ƶ�pָ��
	}
	DoubleNode<T>* q=new DoubleNode<T>(x,p,p->next);
	p->next->prev=q;
	p->next=q;
	return q;
}
//������ĩβ������x,�����ص�ַ
template<typename T>
DoubleNode<T>*CirDoubleList<T>::insert(T x)
{
	DoubleNode<T>*p=new DoubleNode<T>(x,this->head->prev,this->head);
	this->head->prev->next=p;
	this->head->prev=p;
	return p;
}
//���������<<����������
template<typename T>
ostream& operator<<<>(ostream& out,CirDoubleList<T> &list)
{
	out<<"(";
	
	for (DoubleNode<T>* p=list.head->next;p!=list.head;p=p->next)
	{
		out<<p->data;
		if (p->next!=list.head)
		{
			out<<",";
		}
	}
	
	out<<")\n";
	return out;
}

//�Ƴ�iλ�õĽ��
template<typename T>
T CirDoubleList<T>::remove(int i)
{
	DoubleNode<T>*p=this->head->next;
	for (int j=0;p!=this->head&&j<i;j++)
	{
		p=p->next;
	}
	if (i>=0&&p!=this->head)
	{
		T e=p->data;
		p->prev->next=p->next;
		p->next->prev=p->prev;
		delete p;
		return e;
	}
	throw out_of_range("����iָ��Ԫ����ų�����Χ");
}
