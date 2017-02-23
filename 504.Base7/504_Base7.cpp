#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int count;

	while(cin>>a)
	{
		count=b=0;

		while(0!=a)
		{
			b+=(count*10+a%7);
			a/=7;
			count++;
		}

		cout<<b<<endl;
	}
}
