#include <iostream>
#include<exception>
using namespace std;

template<typename T>
class SeqList
{
public:
	SeqList(int length=32);//构造空表，length指定容量
	SeqList(int length,T x);//构造顺序表length个元素，值为x
	SeqList(T values[],int n);//构造顺序表，元素由values数组提供
	SeqList(SeqList<T> &list);//拷贝构造函数重载,***实现深拷贝***
	~SeqList();

	bool empty();
	int count();
	T& operator[](int i);//重载下标运算符
	//对输出运算符进行重载
	friend ostream& operator<<<>(ostream&out,SeqList<T>& list);
	void insert(int i,T x);//在第i位置插入数据x；可以扩容
	void insert(T x);//在顺序表末尾插入数据x；可以扩容
	T remove(int i);//删除第i个元素，并返回删除元素
	void removeAll();//删除顺序表所有元素，未释放空间
	int search(T key,int start);//顺序表查找，从start位置开始查找key,并返回序号
	//已经对运算符"[]"进行了重载，因次不需要get函数   T get(int i)//获得i位置的元素
	SeqList<T>& operator=(SeqList<T>&list);//对赋值函数重载，实现深拷贝


private:
	void init(T values[],int n);//初始化顺序表，此函数构造函数和拷贝构造函数都会用到
								//因此单独写出
protected:
	T *element;//动态数组存储数据表的数据元素
	int length;//顺序表的数组容量
	int n;

};
//******************构造函数~析构函数*****************//
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

//析构函数
template<typename T>
SeqList<T>::~SeqList()
{
	delete []this->element;
}

//*****************基本功能函数***********************//
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

//***重载下标运算符，引用第i个元素
template<typename T>
T& SeqList<T>::operator[](int i)
{
	if (i>=0&&i<this->n)
	{
		return this->element[i];
	}
	throw out_of_range("参数i指定元素信号超出范围\n");
	
}

//***重载输出运算符，遍历顺序表并输出
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
//插入元素
template<typename T>
void SeqList<T>::insert(int i,T x)
{
	if (i<0)i=0;//i<0插入表头
	if(i>this->n)i=this->n;//i>数据个数n，插入表尾
	T* temp=this->element;
	if (this->n==this->length)//如果顺序表已满
	{
		this->length*=2;
		this->element=new T[this->length];//重新申请空间，并将顺序表元素复制过去
		for (int j=0;j<i;i++)//大于i部分与空间未满相同
		{
			this->element[j]=temp[j];
		}

	}
	for (int j=this->n-1;j>=i;j--)//需要从后往前移动
	{
		this->element[j+1]=temp[j];
	}
	if(temp!=this->element)//说明空间已满，重新分配了空间
	{
		delete []temp;//需要将之前的指针所指的顺序表释放；
	}
	this->element[i]=x;
	this->n++;//不要忘了元素个数+1
}
template<typename T>
void SeqList<T>::insert(T x)
{
	insert(this->n,x);
}
//删除元素指定位置元素并返回其值
template<typename T>
T SeqList<T>::remove(int i)
{
	if (i>=0&&i<this->n)
	{
		T e=this->element[i];
		for (int j=i;j<this->n-1;j++)//注意应该是  n-1
		{
			this->element[j]=this->element[j+1];//元素向前移动
		}
		this->n--;//注意元素个数减少
		return e;
	}
	throw out_of_range("i超出索引范围\n");//抛出越界异常
}
//删除数据表所有元素，但不释放空间
template<typename T>
void SeqList<T>::removeAll()
{
	this->n=0;//将元素个数置零即可
}
//顺序表查找，从第start位开始查找元素key,并返回位置
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
//拷贝构造函数重载
SeqList<T>::SeqList(SeqList<T> &list)
{
	this->init(list.element,list.n);
}

template<typename T>
SeqList<T>& SeqList<T>::operator=(SeqList<T>&list)
{
	//this->~SeqList();     ****并没有调用析构函数
	delete []this->element;
	this->init(list.element,list.n);
	return *this;
}


