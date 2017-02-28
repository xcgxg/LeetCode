#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);
int start_index(int *nums, int start, int end, int target);

int main()
{
	int nums[100];
	int returnSize;
	int numsSize;
	int target;
	int *res;

	res=(int *)malloc(2 * sizeof(int));

	scanf("%d",&numsSize);

	for (int i = 0; i < numsSize; i++)
	{
		scanf("%d",&nums[i]);
	}

	scanf("%d",&target);

	res=searchRange(nums,numsSize,target,&returnSize);

	printf("%d %d\n",res[0],res[1]);

}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
	int *res;
	int start=0;
	int end=numsSize-1;

	*returnSize=2;
	res=(int *)malloc(2 * sizeof(int));

	start=start_index(nums, start, end, target);

	if (nums[start] == target)
	{
	    res[0]=start;

	    res[1]=start_index(nums, start, end, target+1);
	    if(nums[res[1]]!=target)
	    {
	    	res[1]--;
	    }

	}
	else
	{
		res[0]=res[1]=-1;
	}

	return res;
}

int start_index(int *nums, int start, int end, int target)
{
	int middle=(start+end)/2;

	while(start<=end)
	{
		if(start == end)
		{			
			break;
		}
		
		if(target > nums[middle])
		{
			start=middle+1;
		}
		else
		{
			end=middle;
		}

		middle=(start+end)/2;
	}

	return start;
}
