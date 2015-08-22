#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BinaryNode
{
public:
	int data;
	//构造结点，data指定元素，left、right指向左孩结点和右孩结点；默认为空
	BinaryNode(int data)
	{
		cout<<this->data;
		data=data;//***此处一定要用this->吗***
	}

	void print()
	{
		cout<<data<<endl;
		cout<<this->data<<endl;
	}
};
int main()
{
	int a=12;
	BinaryNode b(a);
	b.print();
	


	system("pause");
	return 0;
}