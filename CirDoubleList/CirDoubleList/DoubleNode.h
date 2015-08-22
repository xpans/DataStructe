template<typename T>
class DoubleNode
{
public:
	T data;
	DoubleNode<T>*prev,*next;

	DoubleNode();//构造函数，前驱和后驱结点均为空
	DoubleNode(T data,DoubleNode<T>*prev=NULL,DoubleNode<T>*next=NULL);
	//构造函数重载，prev前驱，next后驱，默认值null
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