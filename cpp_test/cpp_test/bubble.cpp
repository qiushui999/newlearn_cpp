#include"test.h"
void bubble(int arr[],int sz)
{
	int a = 0;//
	for (a = 0; a <sz - 1; a++)//��Ҫ��������
	{
		for (int b = 0; b < sz - a - 1; b++)//һ�����򽻻�����
		{
			if (arr[b] > arr[b + 1])
			{
				int tmp = 0;
				tmp = arr[b];
				arr[b] = arr[b+1];
				arr[b + 1] = tmp;
			}
		}
	}
}
int main()

{
	int arr[] = { 1,2,5,4,9,3,7,8,0 };
	int lenth = sizeof(arr) / sizeof(arr[0]);
	cout << "����ǰ";
	for (int i = 0; i < lenth;i++)
	{
		cout << " "<<arr[i];
	}

	cout << endl;
	bubble(arr,lenth);//ð������

	cout << "�����";
	for (int i = 0; i < lenth; i++)
	{
		cout << " " << arr[i];
	}

	system("pause");
	return 0;

}




