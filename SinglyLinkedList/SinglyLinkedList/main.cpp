#include <iostream>
#include "SinglyList.h"
using namespace std;

int main()
{
	SinglyList<char> a("zxcvb",5);
	char values[]={'a','b','c','d','e','f','g','h','e','m'};
	SinglyList<char> list(values,10);
	cout<<list;
	
	cout<<a;
	list+=a;
	cout<<list;
	try
	{
		cout<<list.get(0)<<'\n';
	}
	catch(out_of_range& exc)
	{
		cout<<exc.what();
	}
	list.insert(9,'8');
	cout<<list;
	try
	{
		list.remove(11);
	}
	catch(out_of_range& exc)
	{
		cerr<<exc.what();
	}
	
	list.removeAll();
	
	cout<<list;
	cout<<a;
	system("pause");

	return 0;
}