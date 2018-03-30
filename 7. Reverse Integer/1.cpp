#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

int reverse(int x);

int main()
{
	int x;

	while(cin>>x)
	{
		cout<<reverse(x)<<endl;
	}
}

int reverse(int x)
{
	int flag;
	int i = 1;
	long long res = 0;

	if(x>=0)
	{
		flag = 0;
	}
	else
	{
		flag = 1;
		x=-x;
	}

	while(x != 0)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}

	res = flag?(-res):res;

	if(res > INT_MAX || res < INT_MIN)
	{
		return 0;
	}

	return res;

    
}