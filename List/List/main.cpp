//����������������������������˵��������������������������������������������
//     �������ƣ����������� ɾ �� �顷
//     ���ԣ� c++
//     IDE�汾��visual studio 2012
//     2015.8.4
//     Created by Xpan_hit
//����������������������������������������������������������������������������������
#include <iostream>

using namespace std;

//������
template<typename T>
struct Node
{
	T data;
	Node*next;
};

//�б��࣬�������б�Ĳ���
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
	void CrateList(int);//�����б�
	//��ɾ�Ĳ�---------------------
	void InsertList(int,int);
	void DeleteList(int,int &);
	void Put(int,int);
	void GetElem(int,int &);
	//��������-------------------
	void ReversList();
	//------------------------
	void OutputList();//����б�����
};

int main()
{
	list<T> A;
	//�����������������б�
	A.CrateList(3);
	A.OutputList();
	//������
	A.InsertList(3,56);
	A.OutputList();
	//ɾ����㣬�����ݴ浽e,����ʾ
	int e;
	A.DeleteList(3,e);
	cout<<"\n\nɾ���������ݣ�"<<e<<"\n";
	A.OutputList();
	//���ҵ�һ����㣬����������e����
	A.GetElem(1,e);
	cout<<"\n\n��ý�����ݣ�"<<e<<"\n";
	//����һ������Ϊ5555
	A.Put(1,5555);
	A.OutputList();
	A.ReversList();
	A.OutputList();
	system("pause");
	return 0;
}

//�����б���
void list::CrateList(int n)
{
	//���ͷָ��Ϊ�գ������б�
	if (head==NULL)
	{
		for (int i=0;i<n;i++)
		{
			//pָ���½����
			Node *p;
			p=new Node;//��̬����һ���½��
			cin>>p->data;
			p->next=head;
			head=p;
		}
	} 
	else
	{
		printf("�б��Ѵ���");
	}

}
//������
void list::InsertList(int i,int e)
{
	Node*p,*s,*q;//sָ���½��Ľ��,qָ��p��ǰһ���
	int j=1;
	//�½����
	s=(Node*)new(Node);
	//���½�������ݸ�ֵ
	s->data=e;
	p=head;//pָ���һ�����

	//����б�Ϊ������Ϊ��һ��������
	if (head==NULL)
	{
		printf("�����б�Ϊ�գ���Ϊ��һ��������\n");
		head=s;
		s->next=NULL;
	}
	//������뵽��һλ��
	else if (i==1)
	{
		s->next=head;
		head=s;
	}
	else
	{
		//Ѱ�ҵ�i��λ�� ��p->nextΪ�ն�j<i˵�����б��Ȳ���
		//���µĽ����뵽���
		while (p->next!=NULL&&j<i)
		{
			q=p;
			p=p->next;
			j++;
			//cout<<j;
		}
		if (j<i)
		{
			printf("�б��ȹ������ݽ��������һλ");
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
//ɾ�����  ����i�����ɾ��
void list::DeleteList(int i,int &e)
{
	Node *p,*q;//����ָ���i�����,qָ��p��ǰһ���
	int j=1;
	p=head;//����ָ���һ�����
	if (head==NULL)
	{
		printf("�б�Ϊ��");
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
			printf("ɾ��λ���ѳ����б���\n");
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
//���ҵ�i����㣬�������ݴ��ݵ�e
void list::GetElem(int i,int &e)
{
	Node *p;
	p=head;
	int j=1;
	if (head==NULL)
	{
		printf("�б�Ϊ��");
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
			printf("����λ���ѳ����б���\n");
			system("pause");
			exit(0);
		}
		else
		{
			e=p->data;
		}

	}
}
//����ָ���������
void list::Put(int i,int e)
{
	Node *p;
	p=head;int j=1;
	if (head==NULL)
	{
		printf("�б�Ϊ��");
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
			printf("����λ���ѳ����б���\n");
			system("pause");
			exit(0);
		}
		else
		{
			p->data=e;
		}
	}
}
//����
void list::ReversList()
{
	Node*p=NULL,*next;//nextָ��ͷ������һ���
	while (head!=NULL)
	{
		next=head->next;
		head->next=p;
		p=head;
		head=next;
	}
	head=p;
}
//����б�
void list::OutputList()
{
	Node*p=head;
	if (p!=NULL)
	{
		cout<<"\n\n\n����б�\n";
		while (p!=NULL)
		{
			cout<<p->data<<"\n";
			p=p->next;
		}
	} 
	else
	{
		printf("�б�Ϊ��\n");
	}
}