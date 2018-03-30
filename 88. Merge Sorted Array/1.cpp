#include <iostream>

using namespace std;

void merge(int* nums1, int m, int* nums2, int n);

int main()
{
	int nums1[100];
	int nums2[100];

	int m,n;

	while(cin>>m>>n)
	{
		for (int i = 0; i < m; i++)
		{
			cin>>nums1[i];
		}

		for (int i = 0; i < n; i++)
		{
			cin>>nums2[i];
		}

		merge(nums1, m, nums2, n);

		for (int i = 0; i < m+n; i++)
		{
			cout<<nums1[i]<<' ';
		}

		cout<<endl;
	}
}

void merge(int* nums1, int m, int* nums2, int n)
{
	for (int i = m - 1; i >= 0; i--)
	{
		nums1[i + n] = nums1[i];
	}

	int len = m + n;
	int i_1 = n, i_2 = 0, index = 0;
	while((i_1 < len) && (i_2 < n))
	{
		if(nums1[i_1]<nums2[i_2])
		{
			nums1[index++] = nums1[i_1++];
		}
		else
		{
			nums1[index++] = nums2[i_2++];
		}
	}

	while(i_1<len)
	{
		nums1[index++] = nums1[i_1++];
	}

	while(i_2<n)
	{
		nums1[index++] = nums2[i_2++];
	}

	return;
}