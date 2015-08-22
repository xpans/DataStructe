#include <iostream>
#include "SeqList.h"
using namespace std;
int main()
{
	char valus[]={'a','b','c','d','e','f','g','h','e','m'};
	SeqList<char> list(valus,10);
	//SeqList<char> a;
	cout<<list;
	/*SeqList<char> a(list);
	cout<<"¿½±´£º";
	cout<<a;*/
	SeqList<char> b=list;
	cout<<"¸³Öµ£º";
	cout<<b;

	try
	{
		cout<<list[8]<<"\n";
		char a=list[8];
		cout<<a<<'\n';

	}
	catch(out_of_range &exc)
	{
		cerr<<exc.what();
	}
	cout<<list;
	list.insert(2,'8');
	cout<<list;
	try
	{
		list.remove(11);
	}
	catch(out_of_range& exc)
	{
		cout<<exc.what();
	}
	cout<<list;
	cout<<list.search('e',6)<<endl;
	list.removeAll();
	cout<<list;
	cout<<"*******\n";

	
	system("pause");
	return 0;
}