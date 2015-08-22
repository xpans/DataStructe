#include <iostream>
#include "DoubleNode.h"

using namespace std;

template<typename T>
class CirDoubleList
{
public:
	DoubleNode<T>*head;

	CirDoubleList();
	CirDoubleList(T values[],int n);//构造函数重载
	~CirDoubleList();

	//判断链表是否为空
	bool empty();
	//插入结点，在i位置插入数据x，并返回插入位置
	DoubleNode<T>* insert(T x,int i);
	DoubleNode<T>* insert(T x);//在表尾插入结点X
	friend ostream& operator<<<>(ostream& out,CirDoubleList<T> &list);
	T remove(int i);


private:

};

template<typename T>
//构造函数，数据任意，前驱和后驱均指向头结点，为空双向链表
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

//判断链表是否为空
template<typename T>
bool CirDoubleList<T>::empty()
{
	return this->head->next==this->head;
}
//在下标i位置插入结点x,并返回地址
template<typename T>
DoubleNode<T>* CirDoubleList<T>::insert(T x,int i)
{
	DoubleNode<T>* p=this->head;
	//找到插入位置的前一结点
	for (int j=0;p->next!=head&&j<i;j++)
	{
		p=p->next;//向后移动p指针
	}
	DoubleNode<T>* q=new DoubleNode<T>(x,p,p->next);
	p->next->prev=q;
	p->next=q;
	return q;
}
//在链表末尾插入结点x,并返回地址
template<typename T>
DoubleNode<T>*CirDoubleList<T>::insert(T x)
{
	DoubleNode<T>*p=new DoubleNode<T>(x,this->head->prev,this->head);
	this->head->prev->next=p;
	this->head->prev=p;
	return p;
}
//对运算符“<<”进行重载
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

//移除i位置的结点
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
	throw out_of_range("参数i指定元素序号超出范围");
}
