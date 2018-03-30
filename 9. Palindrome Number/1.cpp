#include <iostream>
#include <stdio.h>

using namespace std;

bool isPalindrome(int x);

int main()
{
	int x;

	while(cin>>x)
	{
		cout<<isPalindrome(x)<<endl;
	}
}

bool isPalindrome(int x)
{
	if(x<0)
	{
		return false;
	}

	if(x<10)
	{
		return true;
	}

	if(0 == x%10)
	{
		return false;
	}

	int y=0;

	while(x>y)
	{
		y=y*10+x%10;

		if(x==y)
			break;
		x/=10;
	}

	return x==y?true:false;
}