#include <iostream>
#include "LinkedQueue.h"

using namespace std;

int main()
{
	LinkedQueue<char> queue;
	//cout<<queue.empty();
	queue.enqueue('a');
	queue.enqueue('b');
	queue.enqueue('c');
	queue.enqueue('d');
	queue.enqueue('e');
	cout<<queue.dequeue();
	cout<<queue.dequeue()//cout�ǴӺ���ǰ����ִ�еģ����λ������ı��ʽ��ִ�У�Ȼ��������ǰ
		<<queue.dequeue()//���ʱ��ǰ����������������һ�����ʽ�ķ���ֵ���������������������
		<<queue.dequeue()//������У���˳���෴
		<<queue.dequeue()
		<<queue.empty();
	cout<<endl<<'a'<<'b'<<'c';

	system("pause");
	return 0;
}