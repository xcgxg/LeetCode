#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);

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
	int start = 0;
	int end =numsSize-1;
	int middle=(start+end)/1;
	int flag=0;
	int *res;

	*returnSize=2;

	while(start<=end)
	{
		if(target == nums[middle])
		{
			flag=1;
			break;
		}
		else if(target > nums[middle])
		{
			start=middle+1;
		}
		else
		{
			end=middle-1;
		}

		middle=(start+end)/1;
	}

	res=(int *)malloc(2 * sizeof(int));

	if (flag)
	{
		int numsSizeLeft=middle;
		int returnSizeLeft;
		int *returnLeft;
		int numsSizeRight=numsSize-middle-1;
		int returnSizeRight;
		int *returnRight;

		returnLeft=searchRange(nums, numsSizeLeft, target, &returnSizeLeft);
		returnRight=searchRange(nums+middle+1, numsSizeRight, target, &returnSizeRight);

		res[0]=(-1 != returnLeft[0])?returnLeft[0]:middle;
		res[1]=(-1 != returnRight[0])?(returnRight[1]+middle+1):middle;

		free(returnLeft);
		free(returnRight);

	}
	else
	{
		res[0]=res[1]=-1;
	}

	return res;
}
