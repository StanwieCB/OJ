#include <iostream>
using namespace std;

//long draw_time(long * arr,int length);
//long wait_time(long * arr, int maxLength);
//long* mint(long*arr1, long*arr2, long*arr3, int length1, int length2, int length3);
int mint(long*lines);

int main()
{
	/*int n, l1n, l2n, l3n;
	long *all, *l1, *l2, *l3;*/
	int n;
	long *all, lines[3] = { 0 };
	long w1 = 0, t1 = 0, w2 = 0, t2 = 0;
	cin >> n;
	all = new long[n];
	for (int i = 0; i < n; i++)
	{
		cin >> all[i];
	}
	//old
	for (int i = 0; i < n; i++)
	{
		int j = i % 3;
		w1 += lines[j];
		lines[j] += all[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (lines[i] > t1)
		{
			t1 = lines[i];
		}
	}
	/*l1 = new long[n];
	l2 = new long[n];
	l3 = new long[n];
	l1n = l2n = l3n = n;
	for (int i = 0; i < n; i++)
	{
		l1[i] = l2[i] = l3[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (i%3==0)
		{
			l1[i / 3] = all[i];
		}
		else if (i%3==1)
		{
			l2[i / 3] = all[i];
		}
		else
		{
			l3[i / 3] = all[i];
		}
	}
	if (draw_time(l1, l1n) > draw_time(l2, l2n))
	{
		t1 = draw_time(l1, l1n);
	}
	else
	{
		t1 = draw_time(l2, l2n);
	}
	t1 = (t1 > draw_time(l3, l3n)) ? t1 : draw_time(l3, l3n);
	w1 = wait_time(l1, l1n) + wait_time(l2, l2n) + wait_time(l3, l3n);*/
	cout <<w1<<" "<< t1 << endl;
	//delete [] l1, l2, l3;

	//new
	for (int i = 0; i < 3; i++)
	{
		lines[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int j = mint(lines);
		w2 += lines[j];
		lines[j] += all[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (lines[i] > t2)
		{
			t2 = lines[i];
		}
	}
	//initialize
	/*l1 = new long[n];
	l2 = new long[n];
	l3 = new long[n];
	l1n = l2n = l3n = n;
	for (int i = 0; i < n; i++)
	{
		l1[i] = l2[i] = l3[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		long * minl;
		minl = mint(l1, l2, l3, l1n, l2n, l3n);
		while (*minl !=0)
		{
			minl++;
		}
		minl[0] = all[i];
	}
	if (draw_time(l1, l1n) > draw_time(l2, l2n))
	{
		t2 = draw_time(l1, l1n);
	}
	else
	{
		t2 = draw_time(l2, l2n);
	}
	t2 = (t2 > draw_time(l3, l3n)) ? t2 : draw_time(l3, l3n);
	w2 = wait_time(l1, l1n) + wait_time(l2, l2n) + wait_time(l3, l3n);*/
	cout << w2 << " " << t2 << endl;
	//delete[] l1, l2, l3,all;
	system("pause");
	return 0;
}

//long draw_time(long * arr,int length)
//{
//	long t = 0;
//	for (int i = 0; i < length; i++)
//	{
//		t += arr[i];
//	}
//	return t;
//}

//long wait_time(long * arr, int maxLength)
//{
//	long t = 0;
//	int l = 0;
//	//count length
//	while (arr[l]!=0&&l<maxLength)
//	{
//		l++;
//	}
//	//count
//	for (int i = 0; i < l; i++)
//	{
//		t += (l - i - 1)*arr[i];
//	}
//	return t;
//}

//long* mint(long*arr1, long*arr2, long*arr3, int length1, int length2,int length3)
//{
//	if (draw_time(arr1,length1)<=draw_time(arr2, length2) && draw_time(arr1, length1)<=draw_time(arr3, length3))
//	{
//		return arr1;
//	}
//	if (draw_time(arr2, length2) < draw_time(arr1, length1) && draw_time(arr2, length2) <= draw_time(arr3, length3))
//	{
//		return arr2;
//	}
//	if (draw_time(arr3, length3) < draw_time(arr1, length1) && draw_time(arr3, length3) < draw_time(arr2, length2))
//	{
//		return arr3;
//	}
//}

int mint(long*lines)
{
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		if (lines[i]<lines[j])
		{
			j = i;
		}
	}
	return j;
}