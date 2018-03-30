#include <iostream>

using namespace std;

bool isValid(string s);

// struct Stack
// {
// 	char sym[1000];
// 	int sp;
// };

int main()
{
	string s;
	while(cin>>s)
	{
		cout<<isValid(s)<<endl;
	}
}

bool isValid(string s)
{
	int len = s.length();

	char *sym = new char[len];
	int sp = -1, index = 0;
	bool match = true;

	while(index<len&&match)
	{
		switch(s[index])
		{
			case '(':
			case '{':
			case '[':
				sym[++sp] = s[index];
				break;

			case ')':
				if(sp>=0 && '(' == sym[sp])
				{
					sp--;
				}
				else
				{
					match = false;
				}
				break;

			case '}':
				if(sp>=0 && '{' == sym[sp])
				{
					sp--;
				}
				else
				{
					match = false;
				}
				break;

			case ']':
				if(sp>=0 && '[' == sym[sp])
				{
					sp--;
				}
				else
				{
					match = false;
				}
				break;
		}

		index++;
	}

	delete []sym;

	if(-1 != sp)
	{
		match = false;
	}

	return match;
}