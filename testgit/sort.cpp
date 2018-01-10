#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void generaterandom(int a[]);
void selectsort(int *, int*);
void quicksort(int i, int j, int a[]);
void insertsort(int i, int j, int a[]);
void shillsort(int, int, int[]);
void sort(int a[], int begin, int end);

constexpr int len = 100;

int main()
{
	int a[len];
	/*for (int i = 0; i < len; ++i)
	{
		a[i] = i + 1;
	}*/
	generaterandom(a);
	int *pbegin = std::begin(a);
	int *pend = std::end(a);
	int arraylength = sizeof(a) / sizeof(a[0]);
	selectsort(pbegin, pend);//选择排序
	//quicksort(0, arraylength - 1, a);//快速排序递归写法
	//insertsort(0, arraylength - 1, a);//插入排序
	//shillsort(0, arraylength - 1, a);//希尔排序

	//sort(a, 0, arraylength - 1);
	cout << "排序后" << endl;
	for (int b : a)
	{
		std::cout << b << " ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}

void generaterandom(int a[])
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = i;
	}
	for (int i = 0; i < len; ++i)
	{
		srand(time(0));
		int changeindex = rand() % (i + 1);
		int temp = a[changeindex];
		a[changeindex] = a[i];
		a[i] = temp;
	}
	cout << "排序前" << endl;
	for (size_t i = 0; i < len; i++)
	{
		cout << a[i] <<" ";
	}
	cout << endl;
}

void selectsort(int *pb, int *pe)
{
	if (pb == pe)
		return;
	int *temp = pb;
	int length = 0;
	while (temp != pe)
	{
		++temp;
		++length;
	}
	int minval;
	int index = 0;
	for (int i = 0; i != length; ++i)
	{
		minval = *(pb + i);
		for (int j = i + 1; j != length; ++j)
		{
			if (*(pb + j) <= minval)
			{
				minval = *(pb + j);
				index = j;
			}
		}
		int tp = *(pb + i);
		*(pb + i) = *(pb + index);
		*(pb + index) = tp;
	}
}

void quicksort(int i, int j, int a[])
{
	if (i >= j)
		return;
	int begin = i;
	int end = j;
	int mark = a[i];
	while(i!=j)
	{
		while (a[j] >= mark&&j > i)
			--j;
		while (a[i] <= mark&&j > i)
			++i;
		int tt = a[i];
		a[i] = a[j];
		a[j] = tt;
	}
	int temp = a[j];
	a[j] = a[begin];
	a[begin] = temp;
	quicksort(begin, j - 1, a);
	quicksort(j + 1, end, a);
}

void insertsort(int i, int j, int a[])
{
	for (int outerindex = i; outerindex <= j; ++outerindex)
	{
		for (int innerindex = outerindex; innerindex > i; --innerindex)
		{
			if (a[innerindex] < a[innerindex - 1])
			{
				//交换
				int temp = a[innerindex];
				a[innerindex] = a[innerindex - 1];
				a[innerindex - 1] = temp;
			}
			else
				break;
		}
	}
}

void shillsort(int begin, int end, int a[])
{
	int h = 1;
	int length = end - begin + 1;
	while (h < length / 3)
		h = 3 * h + 1;
	while (h >= 1)
	{
		//内部进行h序列的希尔排序
		for (int i = h; i <= end; ++i)
		{
			for (int j = i; j-h >= begin; j -= h)
			{
				if (a[j] < a[j - h])
				{
					int temp = a[j];
					a[j] = a[j - h];
					a[j - h] = temp;
				}
				else
					break;
			}
		}
		h /= 3;
	}
}
//归并排序
int acopy[len];//归并排序用作副本
void merge(int a[], int acopy[], int begin, int end)
{
	for (int i = begin; i <= end; ++i)
	{
		acopy[i] = a[i];
	}
	int mid = begin + (end - begin) / 2;
	int i = begin;
	int j = mid + 1;
	int indexer = begin;
	while (indexer <= end)
	{
		if (i > mid) 
			a[indexer] = acopy[j++];
		else if(j > end)
			a[indexer] = acopy[i++];
		else if (acopy[i] < acopy[j])
			a[indexer] = acopy[i++];
		else 
			a[indexer] = acopy[j++];
		++indexer;
	}
}
void sort(int a[], int begin, int end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	sort(a, begin, mid);
	sort(a,  mid + 1, end);
	merge(a, acopy, begin, end);
}