#include <iostream>

using namespace std;

int main()
{
	//�����������print��������BubbleSort
	void print(int*,int);
	void BubbleSort(int*,int);
	//��ʼ������
	int data[]={3,5,8,2,1,9};
	print(data,6);
	//����
	BubbleSort(data,6);
	print(data,6);
	system("pause");
	return 0;
}
//������
void BubbleSort(int*pData,int count)
{
	void print(int*,int);
	int temp;
	for (int i=0;i<count-1;i++)//i:��ʾ�±�Ϊi�������洢 i������С����
		//��Ϊ��⵽count-1λ��ʱ����ʣ��һ������һ������С�� ����Ҫ���
		//��ѭ����cout-1��
	{
		for (int j=count-1;j>i;j--)//�������������ʼ�Ƚϣ��Ӻ���ǰ�Ƚ�
			//j>i:��Ϊ��j��j-1�����бȽϣ���j=iʱ��ʣһ���������ñȽ�
		{
			if (pData[j]<pData[j-1])
			{
				temp=pData[j];
				pData[j]=pData[j-1];
				pData[j-1]=temp;
			}
		}
		cout<<"��"<<i+1<<"ѭ��"<<endl;
		print(pData,count);
		cout<<"-------------------"<<endl;
	}

}
//��ʾ����
void print(int*pData,int count)
{
	for (int i=0;i<count;i++)
	{
		cout<<pData[i]<<"   ";
	}
	cout<<"\n";

}