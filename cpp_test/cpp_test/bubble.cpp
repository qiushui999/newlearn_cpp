#include"test.h"
void bubble(int arr[],int sz)
{
	int a = 0;//
	for (a = 0; a <sz - 1; a++)//需要排序趟数
	{
		for (int b = 0; b < sz - a - 1; b++)//一次排序交换次数
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
	cout << "排序前";
	for (int i = 0; i < lenth;i++)
	{
		cout << " "<<arr[i];
	}

	cout << endl;
	bubble(arr,lenth);//冒泡排序

	cout << "排序后";
	for (int i = 0; i < lenth; i++)
	{
		cout << " " << arr[i];
	}

	system("pause");
	return 0;

}




