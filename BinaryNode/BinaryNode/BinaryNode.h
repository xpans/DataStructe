template<typename T>
class BinaryNode
{
public:
	T data;
	BinaryNode<T>*left,*right;
	//构造结点，data指定元素，left、right指向左孩结点和右孩结点；默认为空
	BinaryNode(T data,BinaryNode<T>*left=NULL,BinaryNode<T>*right=NULL)
	{
		this->data=data;//***此处一定要用this->吗***
		this->left=left;
		this->right=right;
	}
};