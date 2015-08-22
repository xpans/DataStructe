template<typename T>
class SeqQueue
{
public:
	SeqQueue(int length=3);//Ĭ�Ϲ�������Ϊ32�Ŀն���
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
	this->front=this->rear=0;//˵���ǿն���
}

template<typename T>
bool SeqQueue<T>::empty()
{
	return this->front==this->rear;
}

template<typename T>
//�����
void SeqQueue<T>::enqueue(T x)
{
	if (this->front==(this->rear+1)%this->length)//�ж϶����Ƿ�����������Ϊ��ʣһ���ռ�
	{
		//cout<<"����������������";
		T*temp=this->element;
		this->element=new T[this->length*2];//���·���ռ䣬Ϊԭ����2��
		int j=0;
		for (int i=front;i!=rear;i=(i+1)%this->length)//��Ԫ�ظ��Ƶ��½����У�front=0
		{
			this->element[j]=temp[i];
			j++;
		}
		this->front=0;
		this->rear=j;
		this->length*=2;
	}
	this->element[this->rear]=x;//�����
	this->rear=(this->rear+1)%this->length;//��β�±��1��ע��ѭ��
}

//�����У����ض���Ԫ��
template<typename T>
T SeqQueue<T>::dequeue()
{
	if (!empty())
	{
		T e=this->element[this->front];
		this->front=(this->front+1)%this->length;
		return e;
	}
	throw logic_error("Ϊ�ն��У�����ִ�г��Ӳ���\n");
	
}

template<typename T>
SeqQueue<T>::~SeqQueue()
{
	delete[]this->element;
}