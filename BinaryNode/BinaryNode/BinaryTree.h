#include <iostream>
#include "BinaryNode.h"
#include "SeqQueue.h"
#include "LinkedStack.h"


using namespace std;

template<typename T>
class BinaryTree
{
public:
	BinaryNode<T>*root;//***此处需不需要加<T>***
	BinaryTree();//构造空二叉树
	BinaryTree(T prelist[],int n);//以标明空子树的先根序列构造二叉树
	~BinaryTree();//析构函数

	bool empty();
	friend ostream& operator<<<>(ostream& out,BinaryTree<T>&);
	void inOrder();
	void postOrder();
	void inOrderTraverse();//中根次序遍历二叉树，利用栈的非递归算法
	BinaryNode<T>* insert(T x);//插入根结点，其数据为x
	//为parent结点插入左孩或者右孩
	BinaryNode<T>* insert(BinaryNode<T>*parent,T x,bool leftChild);
	//删除二叉树
	void remove();
	//删除parent结点的左孩结点或右孩结点
	void remove(BinaryNode<T>*parent,bool leftChile);
	void levelOrder();//层次遍历，由上至下，由左至右同层遍历
	int depth();//求二叉树深度
	int countLeaf();//求叶子结点个数
private:
	void preOrder(BinaryNode<T>*p);
	void inOrder(BinaryNode<T>*p);
	void postOrder(BinaryNode<T>*p);
	int depth(BinaryNode<T>*p);//递归函数，求以p为根结点的二叉树的深度
	int countLeaf(BinaryNode<T>*p);//递归函数，求以p为根结点的二叉树的叶子结点数
	//删除以P结点为跟的子树
	void remove(BinaryNode<T>*p);
	BinaryNode<T>* create(T prelist[],int n,int &i);
};
//构造空子树
template<typename T>
BinaryTree<T>::BinaryTree()
{
	this->root=NULL;
}
//判断二叉树是否为空
template<typename T>
bool BinaryTree<T>::empty()
{
	return this->root==NULL;
}

//二叉树的先根、中根、后根次序遍历
////////////////////////////////
//1、输出先根次序遍历序列
template<typename T>
ostream& operator<<<>(ostream& out,BinaryTree<T>&btree)
{
	out<<"先根遍历二叉树：";
	btree.preOrder(btree.root);
	out<<endl;
	return out;//保证可以连续输入
}
//递归函数
template<typename T>
void BinaryTree<T>::preOrder(BinaryNode<T>*p)
{
	if (p==NULL)
	{
		cout<<"^"<<" ";
	}
	else
	{
		cout<<p->data<<" ";  //首先输出当前结点，即先输出根节点
		preOrder(p->left);   //按先根次序遍历P的左子树，递归调用
		preOrder(p->right);  //按先根次序遍历P的又子树，递归调用
	}
}
/////////////////////////////////////

//2、输出中根次序遍历序列
template<typename T>
void BinaryTree<T>::inOrder()
{
	cout<<"中根次序遍历二叉树：";
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
	if (p!=NULL)//当左右结点为空时，将无法体现二叉树的结构
	{
		inOrder(p->left);
		cout<<p->data<<' ';
		inOrder(p->right);
	}
}
/////////////////////////////////////////////////////

//3、输出后跟次序遍历
template<typename T>
void BinaryTree<T>::postOrder()
{
	cout<<"后根次序遍历二叉树：";
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

//4、输出中根次序遍历，非递归算法
template<typename T>
void BinaryTree<T>::inOrderTraverse()
{
	cout<<"非递归，中根次序遍历";
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

//利用标明空子树的先根遍历序列构造二叉树，n为指定序列长度
template<typename T>
BinaryTree<T>::BinaryTree(T prelist[],int n)
{
	int i=0;//表示构造第几个结点
	this->root=this->create(prelist,n,i);

}
//递归调用，构造二叉树
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

//插入根结点，元素为x，原根结点作为此结点的左孩
template<typename T>
BinaryNode<T>* BinaryTree<T>::insert(T x)
{
	return this->root=new BinaryNode<T>(x,this->root,NULL);
}
//为parent结点插入左/右孩结点，原左右孩结点为x的左右孩结点
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

//删除子树 递归调用
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
//删除左右子树
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

//删除子树
template<typename T>
void BinaryTree<T>::remove()
{
	this->remove(this->root);
}

template<typename T>
void BinaryTree<T>::levelOrder()
{
	cout<<"层次遍历：";
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
//求二叉树的深度
int BinaryTree<T>::depth()
{
	return this->depth(this->root);
}
template<typename T>
//求以p为根结点的子树的深度，递归调用
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
//求叶子结点的个数
int BinaryTree<T>::countLeaf()
{
	return this->countLeaf(this->root);
}
template<typename T>
//求以p为根结点的子树的叶子结点
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

//析构函数
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	this->remove(this->root);
}

