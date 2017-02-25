#include <stdio.h>

int findMin(int* nums, int numsSize);

int main()
{
	int nums[100];
	int numsSize;
	int min;

	while(~scanf("%d",&numsSize))
	{
		for (int i = 0; i < numsSize; i++)
		{
			scanf("%d",&nums[i]);
		}

		min=findMin(nums, numsSize);

		printf("%d\n", min);
	}
}

/*submission 利用一半的快速排序思想实现*/
int findMin(int* nums, int numsSize)
{
	if(1 == numsSize)
	{
		return nums[0];
	}

    int i=0, j=numsSize-1;
    int tmp=nums[0];

    while(i!=j)
    {
    	while((j>i)&&(nums[j]>=tmp))
    	{
    		j--;
    	}

    	nums[i]=nums[j];

    	while((i<j)&&(nums[i]<=tmp))
    	{
    		i++;
    	}

    	nums[j]=nums[i];
    }

    nums[i]=tmp;

    return findMin(nums, i+1);

}
/*submission 利用一半的快速排序思想实现*/