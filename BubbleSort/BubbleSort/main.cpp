#include <iostream>

using namespace std;

int main()
{
	//声明输出函数print和排序函数BubbleSort
	void print(int*,int);
	void BubbleSort(int*,int);
	//初始化数据
	int data[]={3,5,8,2,1,9};
	print(data,6);
	//排序
	BubbleSort(data,6);
	print(data,6);
	system("pause");
	return 0;
}
//排序函数
void BubbleSort(int*pData,int count)
{
	void print(int*,int);
	int temp;
	for (int i=0;i<count-1;i++)//i:表示下标为i的数将存储 i以下最小的数
		//因为检测到count-1位置时，就剩下一个数，一定是最小数 不需要检测
		//共循环了cout-1次
	{
		for (int j=count-1;j>i;j--)//从最后两个数开始比较，从后往前比较
			//j>i:因为是j和j-1数进行比较，当j=i时就剩一个数，不用比较
		{
			if (pData[j]<pData[j-1])
			{
				temp=pData[j];
				pData[j]=pData[j-1];
				pData[j-1]=temp;
			}
		}
		cout<<"第"<<i+1<<"循环"<<endl;
		print(pData,count);
		cout<<"-------------------"<<endl;
	}

}
//显示函数
void print(int*pData,int count)
{
	for (int i=0;i<count;i++)
	{
		cout<<pData[i]<<"   ";
	}
	cout<<"\n";

}