template<typename T>
class BinaryNode
{
public:
	T data;
	BinaryNode<T>*left,*right;
	//�����㣬dataָ��Ԫ�أ�left��rightָ���󺢽����Һ���㣻Ĭ��Ϊ��
	BinaryNode(T data,BinaryNode<T>*left=NULL,BinaryNode<T>*right=NULL)
	{
		this->data=data;//***�˴�һ��Ҫ��this->��***
		this->left=left;
		this->right=right;
	}
};