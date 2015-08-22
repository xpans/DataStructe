#include <iostream>
#include "BinaryNode.h"
#include "SeqQueue.h"
#include "LinkedStack.h"


using namespace std;

template<typename T>
class BinaryTree
{
public:
	BinaryNode<T>*root;//***�˴��費��Ҫ��<T>***
	BinaryTree();//����ն�����
	BinaryTree(T prelist[],int n);//�Ա������������ȸ����й��������
	~BinaryTree();//��������

	bool empty();
	friend ostream& operator<<<>(ostream& out,BinaryTree<T>&);
	void inOrder();
	void postOrder();
	void inOrderTraverse();//�и��������������������ջ�ķǵݹ��㷨
	BinaryNode<T>* insert(T x);//�������㣬������Ϊx
	//Ϊparent�������󺢻����Һ�
	BinaryNode<T>* insert(BinaryNode<T>*parent,T x,bool leftChild);
	//ɾ��������
	void remove();
	//ɾ��parent�����󺢽����Һ����
	void remove(BinaryNode<T>*parent,bool leftChile);
	void levelOrder();//��α������������£���������ͬ�����
	int depth();//����������
	int countLeaf();//��Ҷ�ӽ�����
private:
	void preOrder(BinaryNode<T>*p);
	void inOrder(BinaryNode<T>*p);
	void postOrder(BinaryNode<T>*p);
	int depth(BinaryNode<T>*p);//�ݹ麯��������pΪ�����Ķ����������
	int countLeaf(BinaryNode<T>*p);//�ݹ麯��������pΪ�����Ķ�������Ҷ�ӽ����
	//ɾ����P���Ϊ��������
	void remove(BinaryNode<T>*p);
	BinaryNode<T>* create(T prelist[],int n,int &i);
};
//���������
template<typename T>
BinaryTree<T>::BinaryTree()
{
	this->root=NULL;
}
//�ж϶������Ƿ�Ϊ��
template<typename T>
bool BinaryTree<T>::empty()
{
	return this->root==NULL;
}

//���������ȸ����и�������������
////////////////////////////////
//1������ȸ������������
template<typename T>
ostream& operator<<<>(ostream& out,BinaryTree<T>&btree)
{
	out<<"�ȸ�������������";
	btree.preOrder(btree.root);
	out<<endl;
	return out;//��֤������������
}
//�ݹ麯��
template<typename T>
void BinaryTree<T>::preOrder(BinaryNode<T>*p)
{
	if (p==NULL)
	{
		cout<<"^"<<" ";
	}
	else
	{
		cout<<p->data<<" ";  //���������ǰ��㣬����������ڵ�
		preOrder(p->left);   //���ȸ��������P�����������ݹ����
		preOrder(p->right);  //���ȸ��������P�����������ݹ����
	}
}
/////////////////////////////////////

//2������и������������
template<typename T>
void BinaryTree<T>::inOrder()
{
	cout<<"�и����������������";
	if (root!=NULL)
	{
		this->inOrder(root);
		cout<<endl;
	}
	else
	{
		cout<<"^";
	}
	
}
template<typename T>
void BinaryTree<T>::inOrder(BinaryNode<T>*p)
{
	if (p!=NULL)//�����ҽ��Ϊ��ʱ�����޷����ֶ������Ľṹ
	{
		inOrder(p->left);
		cout<<p->data<<' ';
		inOrder(p->right);
	}
}
/////////////////////////////////////////////////////

//3���������������
template<typename T>
void BinaryTree<T>::postOrder()
{
	cout<<"������������������";
	this->postOrder(root);
	cout<<endl;
}
template<typename T>
void BinaryTree<T>::postOrder(BinaryNode<T>*p)
{
	if (p!=NULL)
	{
		postOrder(p->left);
		postOrder(p->right);
		cout<<p->data<<' ';
	}

}

//4������и�����������ǵݹ��㷨
template<typename T>
void BinaryTree<T>::inOrderTraverse()
{
	cout<<"�ǵݹ飬�и��������";
	LinkedStack<BinaryNode<T>*> stack;
	BinaryNode<T>* p=this->root;
	while (p!=NULL||!stack.empty())
	{
		if (p!=NULL)
		{
			stack.push(p);
			p=p->left;
		}
		else
		{
			p=stack.pop();
			cout<<p->data<<" ";
			p=p->right;
		}
	}
	cout<<endl;
}
///////////////////////////////////////////////

//���ñ������������ȸ��������й����������nΪָ�����г���
template<typename T>
BinaryTree<T>::BinaryTree(T prelist[],int n)
{
	int i=0;//��ʾ����ڼ������
	this->root=this->create(prelist,n,i);

}
//�ݹ���ã����������
template<typename T>
BinaryNode<T>* BinaryTree<T>::create(T prelist[],int n,int&i)
{
	BinaryNode<T>*p=NULL;
	if (i<n)
	{
		T elem=prelist[i];
		i++;
		if (elem!=NULL)
		{
			p=new BinaryNode<T>(elem);
			p->left=create(prelist,n,i);
			p->right=create(prelist,n,i);
		}
	}
	return p;
}

//�������㣬Ԫ��Ϊx��ԭ�������Ϊ�˽�����
template<typename T>
BinaryNode<T>* BinaryTree<T>::insert(T x)
{
	return this->root=new BinaryNode<T>(x,this->root,NULL);
}
//Ϊparent��������/�Һ���㣬ԭ���Һ����Ϊx�����Һ����
template<typename T>
BinaryNode<T>* BinaryTree<T>::insert(BinaryNode<T>*parent,T x,bool leftChild)
{
	if (parent==NULL)
	{
		return NULL;
	}
	if (leftChild)
	{
		return parent->left=new BinaryNode<T>(x,parent->left,NULL);
	}
	return parent->right=new BinaryNode<T>(x,NULL,parent->right);
}

//ɾ������ �ݹ����
template<typename T>
void BinaryTree<T>::remove(BinaryNode<T>*p)
{
	if (p!=NULL)
	{
		remove(p->left);
		remove(p->right);
		delete p;
	}

}
//ɾ����������
template<typename T>
void BinaryTree<T>::remove(BinaryNode<T>*parent,bool leftChile)
{
	if (parent!=NULL)
	{
		if (leftChile)
		{
			remove(parent->left);
			parent->left=NULL;
		}
		else
		{
			remove(parent->right);
			parent->right=NULL;
		}
	}
}

//ɾ������
template<typename T>
void BinaryTree<T>::remove()
{
	this->remove(this->root);
}

template<typename T>
void BinaryTree<T>::levelOrder()
{
	cout<<"��α�����";
	SeqQueue<BinaryNode<T>*>que;
	BinaryNode<T>*p=this->root;
	while (p!=NULL)
	{
		cout<<p->data;
		if (p->left!=NULL)
		{
			que.enqueue(p->left);
		}
		if (p->right!=NULL)
		{
			que.enqueue(p->right);
		}
		p=que.empty()?NULL:que.dequeue();
	}
	cout<<endl;
}

template<typename T>
//������������
int BinaryTree<T>::depth()
{
	return this->depth(this->root);
}
template<typename T>
//����pΪ��������������ȣ��ݹ����
int BinaryTree<T>::depth(BinaryNode<T>*p)
{
	int depthValue=0;
	if (p==NULL)
	{return depthValue;
	}
	int depthLeft=depth(p->left);
	int depthright=depth(p->right);
	depthValue=1+(depthLeft>depthright?depthLeft:depthright);
	return depthValue;
}

template<typename T>
//��Ҷ�ӽ��ĸ���
int BinaryTree<T>::countLeaf()
{
	return this->countLeaf(this->root);
}
template<typename T>
//����pΪ������������Ҷ�ӽ��
int BinaryTree<T>::countLeaf(BinaryNode<T>*p)
{
	int count=0;
	if (p!=NULL)
	{
		if (p->left==NULL&&p->right==NULL)
		{
			count++;
		}
		else
		{
			count=countLeaf(p->left)+countLeaf(p->right);
		}
	}
	return count;
}

//��������
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	this->remove(this->root);
}

