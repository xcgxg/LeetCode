#include <iostream>

using namespace std;

int removeElement(int* nums, int numsSize, int val);

int main()
{
	int nums[1000];
	int numsSize;
	int val;

	while(cin>>numsSize)
	{
		for (int i = 0; i < numsSize; i++)
		{
			cin>>nums[i];
		}

		cin>>val;

		int new_len = removeElement(nums, numsSize, val);

		cout<<"new len "<<new_len<<endl;

		for (int i = 0; i < new_len; i++)
		{
			cout<<nums[i]<<' ';
		}
		cout<<endl;
	}
}

int removeElement(int* nums, int numsSize, int val)
{
	int count = 0;

	for (int i = 0; i < numsSize; i++)
	{
		while(nums[i] == val && i < numsSize)
		{
			i++;
		}

		if(i < numsSize)
		{
			nums[count++] = nums[i];
		}
	}

	return count;
}