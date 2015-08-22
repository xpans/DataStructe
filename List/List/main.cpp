//—————————————【说明】————————————————————
//     程序名称：《链表——增 删 改 查》
//     语言： c++
//     IDE版本：visual studio 2012
//     2015.8.4
//     Created by Xpan_hit
//—————————————————————————————————————————
#include <iostream>

using namespace std;

//定义结点
template<typename T>
struct Node
{
	T data;
	Node*next;
};

//列表类，包括对列表的操作
template<typename T>
class list
{
private:
	Node* head;
public:
	list()
	{
		head=NULL;
	}
	void CrateList(int);//创建列表
	//增删改查---------------------
	void InsertList(int,int);
	void DeleteList(int,int &);
	void Put(int,int);
	void GetElem(int,int &);
	//链表逆序-------------------
	void ReversList();
	//------------------------
	void OutputList();//输出列表数据
};

int main()
{
	list<T> A;
	//创建包括三个结点的列表
	A.CrateList(3);
	A.OutputList();
	//插入结点
	A.InsertList(3,56);
	A.OutputList();
	//删除结点，其数据存到e,并显示
	int e;
	A.DeleteList(3,e);
	cout<<"\n\n删除结点的数据："<<e<<"\n";
	A.OutputList();
	//查找第一个结点，并将数据用e返回
	A.GetElem(1,e);
	cout<<"\n\n获得结点数据："<<e<<"\n";
	//将第一个结点改为5555
	A.Put(1,5555);
	A.OutputList();
	A.ReversList();
	A.OutputList();
	system("pause");
	return 0;
}

//创建列表功能
void list::CrateList(int n)
{
	//如果头指针为空，创建列表
	if (head==NULL)
	{
		for (int i=0;i<n;i++)
		{
			//p指向新建结点
			Node *p;
			p=new Node;//动态分配一个新结点
			cin>>p->data;
			p->next=head;
			head=p;
		}
	} 
	else
	{
		printf("列表已存在");
	}

}
//插入结点
void list::InsertList(int i,int e)
{
	Node*p,*s,*q;//s指向新建的结点,q指向p的前一结点
	int j=1;
	//新建结点
	s=(Node*)new(Node);
	//对新建结点数据赋值
	s->data=e;
	p=head;//p指向第一个结点

	//如果列表为空则作为第一个结点插入
	if (head==NULL)
	{
		printf("由于列表为空，作为第一个结点插入\n");
		head=s;
		s->next=NULL;
	}
	//如果插入到第一位置
	else if (i==1)
	{
		s->next=head;
		head=s;
	}
	else
	{
		//寻找第i个位置 且p->next为空而j<i说明，列表长度不够
		//将新的结点插入到最后
		while (p->next!=NULL&&j<i)
		{
			q=p;
			p=p->next;
			j++;
			//cout<<j;
		}
		if (j<i)
		{
			printf("列表长度够，数据将插入最后一位");
			p->next=s;
			s->next=NULL;
		}
		else
		{
			s->next=p;
			q->next=s;
		}
		
	}
}
//删除结点  将第i个结点删除
void list::DeleteList(int i,int &e)
{
	Node *p,*q;//用于指向第i个结点,q指向p的前一结点
	int j=1;
	p=head;//首先指向第一个结点
	if (head==NULL)
	{
		printf("列表为空");
	}
	else if (i==1)
	{
		head=head->next;
		e=p->data;
		delete p;
	}
	else
	{
		while (p->next!=NULL&&j<i)
		{
			q=p;
			p=p->next;
			j++;
		}
		if (j<i)
		{
			printf("删除位置已超出列表长度\n");
			system("pause");
			exit(0);
		}
		else
		{
			q->next=p->next;
			e=p->data;
			delete p;
		}

	}

}
//查找第i个结点，并将数据传递到e
void list::GetElem(int i,int &e)
{
	Node *p;
	p=head;
	int j=1;
	if (head==NULL)
	{
		printf("列表为空");
	}
	else
	{
		while (p->next!=NULL&&j<i)
		{
			p=p->next;
			j++;
		}
		if (j<i)
		{
			printf("查找位置已超出列表长度\n");
			system("pause");
			exit(0);
		}
		else
		{
			e=p->data;
		}

	}
}
//更改指定结点数据
void list::Put(int i,int e)
{
	Node *p;
	p=head;int j=1;
	if (head==NULL)
	{
		printf("列表为空");
	} 
	else
	{
		while (p->next!=NULL&&j<i)
		{
			p=p->next;
			j++;
		}
		if (j<i)
		{
			printf("更改位置已超出列表长度\n");
			system("pause");
			exit(0);
		}
		else
		{
			p->data=e;
		}
	}
}
//逆序
void list::ReversList()
{
	Node*p=NULL,*next;//next指向头结点的下一结点
	while (head!=NULL)
	{
		next=head->next;
		head->next=p;
		p=head;
		head=next;
	}
	head=p;
}
//输出列表
void list::OutputList()
{
	Node*p=head;
	if (p!=NULL)
	{
		cout<<"\n\n\n输出列表\n";
		while (p!=NULL)
		{
			cout<<p->data<<"\n";
			p=p->next;
		}
	} 
	else
	{
		printf("列表为空\n");
	}
}