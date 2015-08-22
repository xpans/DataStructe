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
	cout<<queue.dequeue()//cout是从后往前进行执行的，最后位置输出的表达式先执行，然后依次往前
		<<queue.dequeue()//输出时从前往后输出，即输出第一个表达式的返回值，依次向后。所以这样连续
		<<queue.dequeue()//输出队列，会顺序相反
		<<queue.dequeue()
		<<queue.empty();
	cout<<endl<<'a'<<'b'<<'c';

	system("pause");
	return 0;
}