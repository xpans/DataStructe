#include "LinkedStack.h"
int main()
{
	char e1;
	LinkedStack<char> stacks;
	string values="abcd";
	//cout<<values.length();
	for (int i=0;i<4;i++)
	{
		stacks.push(values[i]);
	}



	try
	{
		e1=stacks.pop();
		stacks.pop();
		stacks.pop();
		
	}
	catch(logic_error&exc)
	{
		cerr<<exc.what();
	}
	cout<<e1;
	try
	{
		cout<<stacks.get();
	}
	catch(logic_error&exc)
	{
		cerr<<exc.what();
	}

	system("pause");
	return 0;
}