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

    int flag=0;
    int pos;

	for (int i = 0; i < numsSize-1; i++)
    {
        if(nums[i+1]<nums[i])
        {
            flag=1;
            pos=i+1;
            break;
        }
    }

    if (flag)
    {
        return nums[pos];
    }
    else
    {
        return nums[0];
    }

}
/*submission 利用一半的快速排序思想实现*/