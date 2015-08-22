template<typename T>
class DoubleNode
{
public:
	T data;
	DoubleNode<T>*prev,*next;

	DoubleNode();//���캯����ǰ���ͺ�������Ϊ��
	DoubleNode(T data,DoubleNode<T>*prev=NULL,DoubleNode<T>*next=NULL);
	//���캯�����أ�prevǰ����next������Ĭ��ֵnull
	~DoubleNode();

private:

};

template<typename T>
DoubleNode<T>::DoubleNode()
{
	this->prev=NULL;
	this->next=NULL;
}
template<typename T>
DoubleNode<T>::DoubleNode(T data,DoubleNode<T>*prev,DoubleNode<T>*next)
{
	this->data=data;
	this->prev=prev;
	this->next=next;
}
template<typename T>
DoubleNode<T>::~DoubleNode()
{
}