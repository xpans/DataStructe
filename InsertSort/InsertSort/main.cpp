//-------插入排序-----
//【1】直接插入排序（Insertion Sort）
//是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对未排序的数据，在已排序序列
//中从后向前扫描，找到相应位置并插入。
//----插入排序算法的一般步骤：
//    1.从第一个元素开始，该元素可以认为已被排序；
//    2.取出下一个元素，在已经排序的元素序列中从后向前扫描；
//    3.如果该元素（已排序）大于新元素，将该元素移到下一个位置；
//    4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
//    5.将新元素插入到该位置后，重复2~5
//【2】希尔排序（shell sort）
//也称为递减增量排序算法，是插入排序的一种高速而稳定的改进版本。
//希尔排序是基于插入排序的以下两点性质而提出改进方法的:
//1.插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率；
//2.但插入排序一般来说是低效的， 因为插入排序每次只能将数据移动一位。
//---希尔排序的一般步骤为：
//	1.先取一个小于n的整数d1作为第一个增量，把文件的全部记录分成d1个组。
//	所有距离为dl的倍数的记录放在同一个组中，在各组内进行直接插人排序。
//	2.取第二个增量d2<d1重复上述的分组和排序，直至所取的增量dt=1(dt<dt-l<…<d2<d1)，
//	即所有记录放在同一组中进行直接插入排序为止。
//	步长的选择是希尔排序的重要部分。只要最终步长为1任何步长串行都可以工作。
//	算法最开始以一定的步长进行排序。然后会继续以一定步长进行排序，最终算法以步长为1进行排序。
//	当步长为1时，算法变为插入排序，这就保证了数据一定会被排序。

#include <iostream>
using namespace std;
int main()
{
	void InsertionSort(int*,int);
	void ShellSort(int*,int);
	void print(int*,int);

	int Data[]={5,3,4,7,8,1,9,2,18,15};
	print(Data,10);
	//直接插入排序
	//InsertionSort(Data,10);
	ShellSort(Data,10);
	print(Data,10);
	system("pause");
	return 0;
}
//直接插入排序
void InsertionSort(int*pData,int count)
{
	for (int j=1;j<count;j++)//下标j数与下标0~j-1数进行比较
							//注意0-j-1数已经排过序（由小到大）
	{
		int key=pData[j];
		int i=j-1;
		while (key<pData[i]&&i>=0)
		{
			pData[i+1]=pData[i];//如果数j<j-1，则j-1数向后移
			i--;
		}//i<key<i+1时跳出循环
		pData[i+1]=key;
	}
}
//ShellSort希尔排序是直接插入排序的特例
//直接插入每次增量为1，希尔排序每次增量为一定的步长，逐渐减小
//最后步长为1
void ShellSort(int*pData,int count)
{
	int h=1;
	while (h<count)
	{
		h=3*h+1;//确定h-1是3的倍数，保证最后是以1为步长
	}
	while (h>0)
	{
		for (int j=1;j<count;j++)
		{
			int key=pData[j];
			int i=j-h;
			while (i>=0&&key<pData[i])
			{
				pData[i+h]=pData[i];
				i=i-h;
			}
			pData[i+h]=key;
		}
		h=h/3;
	}
}
void print(int*pData,int count)
{
	for (int i=0;i<count;i++)
	{
		cout<<pData[i]<<"   ";
	}
	cout<<"\n";

}
