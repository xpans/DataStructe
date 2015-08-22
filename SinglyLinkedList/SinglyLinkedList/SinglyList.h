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

	//重载运算符<<,输出列表元素****此处不用声明友元函数也可，因为没有访问私有变量
	friend ostream& operator<<<>(ostream& out,SinglyList<T>&list);
	T get(int i);
	Node<T>* insert(int i,T x);//插入x作为第i个元素，如果i<0就插在第一位，如果i>表长插入最后
	T remove(int i);//移除位置为i的元素，如果超出索引则抛出异常
	void removeAll();//清空表单，只剩下头结点
	bool empty();//判断单链表是否是空
	virtual void operator+=(SinglyList<T>&list);//将list链表链接到当前链表之后

private:

};


template<typename T>
//构造空链表
SinglyList<T>::SinglyList()
{
	this->head=new Node<T>();
}

template<typename T>
//构造单链表，由数组value元素赋值
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
//单链表遍历算法，重载运算符<<，输出所有元素
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
//返回第i个元素，若不符合要求，则抛出越界异常
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
	throw out_of_range("参数i指定序号超出索引范围");
	
}

//在i位置插入x元素
template<typename T>
Node<T>* SinglyList<T>::insert(int i,T x)
{
	Node<T>*p=this->head;
	for (int j=0;p->next!=NULL&&j<i;j++)//当p->next==null说明已经到队尾了
										//如果p！=null说明，运行完p==null;
	{
		p=p->next;
	}
	p->next=new Node<T>(x,p->next);
	return p->next;
}

template<typename T>
//移除位置为i的元素,并判断i是否越界
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
	throw out_of_range("移除结点时，参数i指定元素序号超出索引范围\n");
}

template<typename T>
//清空表单
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
		this->remove(0);//每次循环都是移除第0个结点
	}
}

//判断列表是否为空
template<typename T>
bool SinglyList<T>::empty()
{
	return this->head->next==NULL;
}

template<typename T>
//使链表链接到当前链表后
void SinglyList<T>::operator+=(SinglyList<T> &list)
{
	Node<T>*p=this->head;
	while (p->next!=NULL)
	{
		p=p->next;
	}
	p->next=list.head->next;
	list.head->next=NULL;//????不加此句程序会出错***出错位置在公式结束时，why
	//程序结束是需要对 对象进行析构。析构的顺序是先释放list，在释放当前链表，这样
	//释放后接的结点就会出错。
	//解决方法，可以重载‘=’运算符，进行深拷贝，并参数设为对象参数，而不是引用参数
}




template<typename T>
SinglyList<T>::~SinglyList()
{
	this->removeAll();
	delete this->head;
}