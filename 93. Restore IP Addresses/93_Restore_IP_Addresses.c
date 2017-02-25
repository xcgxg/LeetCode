#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** restoreIpAddresses(char* s, int* returnSize);
char *judge_ip(char *s, int pos[]);

int main()
{
	char s[100];
	char **ip;
	int returnSize;

	while(~scanf("%s", s))
	{
		ip=restoreIpAddresses(s, &returnSize);

		for (int i = 0; i < returnSize; i++)
		{
			printf("%s\n", ip[i]);

			free(ip[i]);
		}

		free(ip);
	}
}

char *judge_ip(char *s, int pos[])
{
	int s_len=strlen(s);
	char *ip = NULL;
	int num=0;
	int flag=1;

	for (int i = 1; i < 5; i++)
	{
		num=0;

		for (int o = pos[i-1]+1; o <= pos[i]; o++)
		{
			num=num*10+s[o]-'0';
		}//printf("%d\n", num);

		if(num > 255)
		{
			flag=0;
			break;
		}
		else if((0 != num) && (s[pos[i-1]+1] == '0'))
		{
			flag = 0;
			break;
		}
		else if((0 == num) && (pos[i]-pos[i-1]>1))
		{
			flag=0;
			break;
		}
	}

	if(flag)
	{
		ip=(char *)malloc(s_len * sizeof(char));

		for (int i = 1; i < 5; i++)
		{
			for (int o = pos[i-1]+1; o <=pos[i]; o++)
			{
				ip[o+i-1]=s[o];
			}

			if(i!=4)
			{
				ip[pos[i]+i]='.';
			}
			else
			{
				ip[pos[i]+i]='\0';
			}
		}
	}

	return ip;
}

char** restoreIpAddresses(char* s, int* returnSize)
{
	int len=strlen(s);
	int pos[5]={ -1, 0, 0, 0, len-1 };
	char **ip;
	char *tmp;

	ip=(char **)malloc(500 * sizeof(char **));
	*returnSize=0;
	
	if((len <= 12) && (len >= 4))
	{
		for (int i = 0; i < len - 3; i++)
		{
			pos[1]=i;

			for (int o = i + 1; o < len - 2; o++)
			{
				pos[2]=o;

				for (int j = o + 1; j < len - 1; j++)
				{
					pos[3]=j;
					tmp = judge_ip(s, pos);

					if(NULL != tmp)
					{
						ip[*returnSize] = tmp;
						(*returnSize)++;
					}
				}
			}
		}
	}

	return ip;

}