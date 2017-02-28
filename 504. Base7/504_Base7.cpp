#include <iostream>

using namespace std;

/*submission*/
class Solution 
{
public:
    string convertToBase7(int num) 
    {
        string res="";
        int isNeg=num<0?1:0;
        
        if(isNeg)
    	{
    	    num=-num;
    	}
    
        if(0 == num)
        {
            res="0";
        }
        else
        {
            while(0!=num)
        	{
        		res=(char)((num%7)+'0')+res;
        		num/=7;
        	}
        	
        	if(isNeg)
        	{
        	    res='-'+res;
        	}
        }

    	return res;
    }
};
/*submission*/

int main()
{
	Solution s;
	int num;

	cin>>num;
	cout<<s.convertToBase7(num)<<endl;
}
