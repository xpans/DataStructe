template<typename T>
class SeqQueue
{
public:
	SeqQueue(int length=3);//默认构造容量为32的空队列
	~SeqQueue();

	bool empty();
	void enqueue(T x);
	T dequeue();

private:
	T* element;
	int length;
	int front,rear;
};

template<typename T>
SeqQueue<T>::SeqQueue(int length)
{
	this->element=new T[length];
	this->length=length;
	this->front=this->rear=0;//说明是空队列
}

template<typename T>
bool SeqQueue<T>::empty()
{
	return this->front==this->rear;
}

template<typename T>
//入队列
void SeqQueue<T>::enqueue(T x)
{
	if (this->front==(this->rear+1)%this->length)//判断队列是否已满，条件为仅剩一个空间
	{
		//cout<<"队列满，扩充容量";
		T*temp=this->element;
		this->element=new T[this->length*2];//重新分配空间，为原来的2倍
		int j=0;
		for (int i=front;i!=rear;i=(i+1)%this->length)//将元素复制到新建队列，front=0
		{
			this->element[j]=temp[i];
			j++;
		}
		this->front=0;
		this->rear=j;
		this->length*=2;
	}
	this->element[this->rear]=x;//入队列
	this->rear=(this->rear+1)%this->length;//队尾下标加1，注意循环
}

//出队列，返回队首元素
template<typename T>
T SeqQueue<T>::dequeue()
{
	if (!empty())
	{
		T e=this->element[this->front];
		this->front=(this->front+1)%this->length;
		return e;
	}
	throw logic_error("为空队列，不能执行出队操作\n");
	
}

template<typename T>
SeqQueue<T>::~SeqQueue()
{
	delete[]this->element;
}