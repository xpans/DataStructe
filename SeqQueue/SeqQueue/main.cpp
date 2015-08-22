#include <iostream>
#include "SeqQueue.h"

using namespace std;

int main()
{
	SeqQueue<char> queue;
	queue.enqueue('a');
	queue.enqueue('b');
	queue.enqueue('c');
	try
	{
		cout<<queue.dequeue();
	}
	catch(logic_error&exc)
	{
		cerr<<exc.what();
	}
	
	cout<<queue.empty();
	cout<<queue.dequeue();
	system("pause");
	return 0;
}
