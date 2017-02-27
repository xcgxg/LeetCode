#include <iostream>
#include <cstring>

using namespace std;

int romanToInt(string s);

int main()
{
	string a;

	while(cin>>a)
	{
		cout<<romanToInt(a)<<endl;
	}
}

int single_roman(char c)
{
	int res;

	switch(c)
	{
		case 'I':
			res=1;
			break;
		case 'V':
			res=5;
			break;
		case 'X':
			res=10;
			break;
		case 'L':
			res=50;
			break;
		case 'C':
			res=100;
			break;
		case 'D':
			res=500;
			break;
		case 'M':
			res=1000;
			break;
	}

	return res;
}

int romanToInt(string s) 
{
    int len=s.length();
	int	res=0;
	int reg=0;
	int tmp;

	for (int i = 0; i <len; i++)
	{
		tmp=single_roman(s[i]);

		if(0 == reg)
		{
			reg=tmp;
		}
		else
		{
			if(reg<tmp)
			{
				res+=(tmp-reg);
				reg=0;
			}
			else
			{
				res+=reg;
				reg=tmp;
			}
		}
	}

	if(0 != reg)
	{
		res+=tmp;
	}

	return res;
}