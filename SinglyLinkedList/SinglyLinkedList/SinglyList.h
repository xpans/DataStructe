#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class SinglyList
{
public:
	Node<T>* head;

	SinglyList();
	SinglyList(T values[],int n);
	~SinglyList();

	//���������<<,����б�Ԫ��****�˴�����������Ԫ����Ҳ�ɣ���Ϊû�з���˽�б���
	friend ostream& operator<<<>(ostream& out,SinglyList<T>&list);
	T get(int i);
	Node<T>* insert(int i,T x);//����x��Ϊ��i��Ԫ�أ����i<0�Ͳ��ڵ�һλ�����i>���������
	T remove(int i);//�Ƴ�λ��Ϊi��Ԫ�أ���������������׳��쳣
	void removeAll();//��ձ���ֻʣ��ͷ���
	bool empty();//�жϵ������Ƿ��ǿ�
	virtual void operator+=(SinglyList<T>&list);//��list�������ӵ���ǰ����֮��

private:

};


template<typename T>
//���������
SinglyList<T>::SinglyList()
{
	this->head=new Node<T>();
}

template<typename T>
//���쵥����������valueԪ�ظ�ֵ
SinglyList<T>::SinglyList(T values[],int n)
{
	this->head=new Node<T>();
	Node<T>*p=this->head;
	for (int i=0;i<n;i++)
	{
		p->next=new Node<T>(values[i]);
		p=p->next;
	}
}

template<typename T>
//����������㷨�����������<<���������Ԫ��
ostream& operator<<<>(ostream& out,SinglyList<T>&list)
{
	out<<"(";
	for (Node<T>*p=list.head->next;p!=NULL;p=p->next)
	{
		out<<p->data;
		if (p->next!=NULL)
		{
			cout<<",";
		}
	}
	cout<<")\n";
	return out;
}

template<typename T>
//���ص�i��Ԫ�أ���������Ҫ�����׳�Խ���쳣
T SinglyList<T>::get(int i)
{
	Node<T>*p=this->head->next;
	for (int j=0;p!=NULL&&j<i;j++)
	{
		p=p->next;
	}if (i>=0&&p!=NULL)
	{
		return p->data;
	}
	throw out_of_range("����iָ����ų���������Χ");
	
}

//��iλ�ò���xԪ��
template<typename T>
Node<T>* SinglyList<T>::insert(int i,T x)
{
	Node<T>*p=this->head;
	for (int j=0;p->next!=NULL&&j<i;j++)//��p->next==null˵���Ѿ�����β��
										//���p��=null˵����������p==null;
	{
		p=p->next;
	}
	p->next=new Node<T>(x,p->next);
	return p->next;
}

template<typename T>
//�Ƴ�λ��Ϊi��Ԫ��,���ж�i�Ƿ�Խ��
T SinglyList<T>::remove(int i)
{
	Node<T>*p=this->head;
	for (int j=0;p->next!=NULL&&j<i;j++)
	{
		p=p->next;
	}
	if (i>=0&&p->next!=NULL)
	{
		Node<T>*q=p->next;
		T e=q->data;
		p->next=q->next;
		delete q;
		return e;
	}
	throw out_of_range("�Ƴ����ʱ������iָ��Ԫ����ų���������Χ\n");
}

template<typename T>
//��ձ�
void SinglyList<T>::removeAll()
{
	/*Node<T>*p=this->head->next;
	Node<T>*q;
	this->head->next=NULL;
	while (p!=NULL)
	{
		q=p;
		p=p->next;
		delete q;
	}*/
	Node<T>*p=this->head->next;
	while (p!=NULL)
	{
		p=p->next;
		this->remove(0);//ÿ��ѭ�������Ƴ���0�����
	}
}

//�ж��б��Ƿ�Ϊ��
template<typename T>
bool SinglyList<T>::empty()
{
	return this->head->next==NULL;
}

template<typename T>
//ʹ�������ӵ���ǰ�����
void SinglyList<T>::operator+=(SinglyList<T> &list)
{
	Node<T>*p=this->head;
	while (p->next!=NULL)
	{
		p=p->next;
	}
	p->next=list.head->next;
	list.head->next=NULL;//????���Ӵ˾��������***����λ���ڹ�ʽ����ʱ��why
	//�����������Ҫ�� �������������������˳�������ͷ�list�����ͷŵ�ǰ��������
	//�ͷź�ӵĽ��ͻ����
	//����������������ء�=��������������������������Ϊ������������������ò���
}




template<typename T>
SinglyList<T>::~SinglyList()
{
	this->removeAll();
	delete this->head;
}