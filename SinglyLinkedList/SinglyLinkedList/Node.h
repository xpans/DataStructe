template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node()
	{
		this->next=NULL;
	}
	Node(T data,Node<T>*next=NULL)
	{
		this->data=data;
		this->next=next;
	}

};
