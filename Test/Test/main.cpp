#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BinaryNode
{
public:
	int data;
	//�����㣬dataָ��Ԫ�أ�left��rightָ���󺢽����Һ���㣻Ĭ��Ϊ��
	BinaryNode(int data)
	{
		cout<<this->data;
		data=data;//***�˴�һ��Ҫ��this->��***
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