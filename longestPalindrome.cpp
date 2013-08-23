#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Solution
{
//write your function to calculate here
public: 
    string longestPalindrome(string s)
    {
        if(s.size()<=1) return s;
        int size = s.size();
        int result=1;
        int start=0;
        for(int i=0;i<size;i++)
        {
            int j,k;
            j=i-1;k=i;
            int temp=0;
            int tag=0;
            while(j>=0 && k<size && s[j]==s[k])
            {
                tag=1;
                temp+=2;
                j--;k++;
            }
            if(result<temp)
            {
                result=temp;
                if(tag==1)
                    start=j+1;
            }
            j=i-1;k=i+1;
            temp=1;
            tag=0;
            while(j>=0 && k<size && s[j]==s[k])
            {
                tag=1;
                temp+=2;
                j--;k++;
            }
            if(result<temp)
            {
                result = temp;
                if(tag==1)
                {
                    start=j+1;
                }
            }
        }
        return s.substr(start,result);
    }

};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here

//solute your problem here
	string result = my_solution->longestPalindrome("aba");

//print your output here
    cout<<result<<endl;
}
