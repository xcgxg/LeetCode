#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int* twoSum(int* nums, int numsSize, int target);

int main()
{
	int nums[100] = {};
	int *res=0;
	int numsSize = 0;
	int target;

	cin>>numsSize;

	for (int i = 0; i < numsSize; i++)
	{
		cin>>nums[i];
	}

	cin >>target;

	res = twoSum(nums, numsSize, target);

	cout<<res[0]<<' '<<res[1]<<endl;

	free(res);
}

int* twoSum(int* nums, int numsSize, int target)
{
    int *res = (int *)malloc(8);

    for (int i = 0; i < numsSize - 1; i++)
    {
    	for (int o = i + 1; o < numsSize; o++)
    	{
    		if(nums[i]+nums[o] == target)
    		{
    			res[0]=i;
    			res[1]=o;

    			return res;
    		}
    	}
    }

    return res;
}