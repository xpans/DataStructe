
#include "CirDoubleList.h"

int main()
{
	CirDoubleList<char> list("abcdefghijddddd",15);
	//CirDoubleList<char> list;
	//list.insert('4',-44);
	//list.insert('v',0);
	list.insert('3');
	try
	{
		list.remove(16);
	}
	catch(out_of_range&exc)
	{
		cerr<<exc.what();
	}
	
	cout<<list;


	system("pause");
	return 0;
}