#include <iostream>
#include <limits.h>

using namespace std;

int maxSubArray(int* nums, int numsSize);

int main()
{
	int nums[100];
	int numsSize;

	while(cin>>numsSize)
	{
		for (int i = 0; i < numsSize; i++)
		{
			cin>>nums[i];
		}

		cout<<maxSubArray(nums, numsSize)<<endl;
	}
}

int maxSubArray(int* nums, int numsSize)
{
	if(0 == numsSize)
	{
		return INT_MIN;
	}
	if(1 == numsSize)
	{
		return nums[0];
	}

	int mid = numsSize/2;
	int left_sum = 0, left_max = INT_MIN;
	int right_sum = 0, right_max = INT_MIN;
	int res_mid;

	for (int i = mid; i >= 0; i--)
	{
		left_sum += nums[i];
		left_max = (left_max>left_sum)?left_max:left_sum;
	}
	for (int i = mid; i < numsSize; i++)
	{
		right_sum += nums[i];
		right_max = (right_max>right_sum)?right_max:right_sum;
	}

	res_mid = left_max + right_max - nums[mid];

	int res_left = maxSubArray(nums, mid);
	int res_right = maxSubArray(nums + mid + 1, numsSize - mid - 1);
	int res;

	res = (res_left>res_mid)?res_left:res_mid;
	res = (res>res_right)?res:res_right;

	return res;
}