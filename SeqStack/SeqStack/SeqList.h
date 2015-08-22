#include <iostream>
#include<exception>
using namespace std;

template<typename T>
class SeqList
{
public:
	SeqList(int length=32);//����ձ�lengthָ������
	SeqList(int length,T x);//����˳���length��Ԫ�أ�ֵΪx
	SeqList(T values[],int n);//����˳���Ԫ����values�����ṩ
	SeqList(SeqList<T> &list);//�������캯������,***ʵ�����***
	~SeqList();

	bool empty();
	int count();
	T& operator[](int i);//�����±������
	//������������������
	friend ostream& operator<<<>(ostream&out,SeqList<T>& list);
	void insert(int i,T x);//�ڵ�iλ�ò�������x����������
	void insert(T x);//��˳���ĩβ��������x����������
	T remove(int i);//ɾ����i��Ԫ�أ�������ɾ��Ԫ��
	void removeAll();//ɾ��˳�������Ԫ�أ�δ�ͷſռ�
	int search(T key,int start);//˳�����ң���startλ�ÿ�ʼ����key,���������
	//�Ѿ��������"[]"���������أ���β���Ҫget����   T get(int i)//���iλ�õ�Ԫ��
	SeqList<T>& operator=(SeqList<T>&list);//�Ը�ֵ�������أ�ʵ�����


private:
	void init(T values[],int n);//��ʼ��˳����˺������캯���Ϳ������캯�������õ�
								//��˵���д��
protected:
	T *element;//��̬����洢���ݱ������Ԫ��
	int length;//˳������������
	int n;

};
//******************���캯��~��������*****************//
template<typename T>
SeqList<T>::SeqList(int length)
{
	this->element=new T[length];
	this->length;
	this->n=0;
}
template<typename T>
SeqList<T>::SeqList(int length,T x)
{
	this->element=new T[length];
	this->length=this->n=length;
	for (int i=0;i<this->n;i++)
	{
		this->element[i]=x;
	}
}
template<typename T>
SeqList<T>::SeqList(T values[],int n)
{
	this->init(values,n);
}

template<typename T>
void SeqList<T>::init(T values[],int n)
{
	this->length=n*2;
	this->element=new T[this->length];
	this->n=n;
	for (int i=0;i<n;i++)
	{
		this->element[i]=values[i];
	}
}

//��������
template<typename T>
SeqList<T>::~SeqList()
{
	delete []this->element;
}

//*****************�������ܺ���***********************//
template<typename T>
bool SeqList<T>::empty()
{
	return this->n==0;
}
template<typename T>
int SeqList<T>::count()
{
	return this->n;
}

//***�����±�����������õ�i��Ԫ��
template<typename T>
T& SeqList<T>::operator[](int i)
{
	if (i>=0&&i<this->n)
	{
		return this->element[i];
	}
	throw out_of_range("����iָ��Ԫ���źų�����Χ\n");
	
}

//***������������������˳������
template<typename T>
ostream& operator<<<>(ostream&out,SeqList<T>& list)
{
	cout<<'(';
	for (int i=0;i<list.n;i++)
	{
		cout<<list.element[i]<<',';
	}
	cout<<')'<<endl;
	return out;
}
//����Ԫ��
template<typename T>
void SeqList<T>::insert(int i,T x)
{
	if (i<0)i=0;//i<0�����ͷ
	if(i>this->n)i=this->n;//i>���ݸ���n�������β
	T* temp=this->element;
	if (this->n==this->length)//���˳�������
	{
		this->length*=2;
		this->element=new T[this->length];//��������ռ䣬����˳���Ԫ�ظ��ƹ�ȥ
		for (int j=0;j<i;i++)//����i������ռ�δ����ͬ
		{
			this->element[j]=temp[j];
		}

	}
	for (int j=this->n-1;j>=i;j--)//��Ҫ�Ӻ���ǰ�ƶ�
	{
		this->element[j+1]=temp[j];
	}
	if(temp!=this->element)//˵���ռ����������·����˿ռ�
	{
		delete []temp;//��Ҫ��֮ǰ��ָ����ָ��˳����ͷţ�
	}
	this->element[i]=x;
	this->n++;//��Ҫ����Ԫ�ظ���+1
}
template<typename T>
void SeqList<T>::insert(T x)
{
	insert(this->n,x);
}
//ɾ��Ԫ��ָ��λ��Ԫ�ز�������ֵ
template<typename T>
T SeqList<T>::remove(int i)
{
	if (i>=0&&i<this->n)
	{
		T e=this->element[i];
		for (int j=i;j<this->n-1;j++)//ע��Ӧ����  n-1
		{
			this->element[j]=this->element[j+1];//Ԫ����ǰ�ƶ�
		}
		this->n--;//ע��Ԫ�ظ�������
		return e;
	}
	throw out_of_range("i����������Χ\n");//�׳�Խ���쳣
}
//ɾ�����ݱ�����Ԫ�أ������ͷſռ�
template<typename T>
void SeqList<T>::removeAll()
{
	this->n=0;//��Ԫ�ظ������㼴��
}
//˳�����ң��ӵ�startλ��ʼ����Ԫ��key,������λ��
template<typename T>
int SeqList<T>::search(T key,int start)
{
	for (int i=start;i<this->n;i++)
	{
		if (this->element[i]==key)
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
//�������캯������
SeqList<T>::SeqList(SeqList<T> &list)
{
	this->init(list.element,list.n);
}

template<typename T>
SeqList<T>& SeqList<T>::operator=(SeqList<T>&list)
{
	//this->~SeqList();     ****��û�е�����������
	delete []this->element;
	this->init(list.element,list.n);
	return *this;
}


