#include <iostream>
using namespace std;

int main()
{
	int n, *arr;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i]==0)
		{
			cout << "no" << endl;
		}
		else cout << "yes" << endl;
	}
	system("pause");
	return 0;
}