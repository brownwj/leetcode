#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    string minWindow(string S, string T)
    {
        if(S.size()<T.size()) return "";
        int expected[256];
        int current[256];
        memset(expected,0,256*sizeof(expected[0]));
        memset(current, 0, 256*sizeof(current[0]));
        for(int i=0;i<T.size();i++)
        {
            expected[T[i]]++;
        }
        int start=0;
        int hit=0;
        int min_window = 0x7FFFFFFF;
        int min_start=0;
        for(int i=0;i<S.size();i++)
        {
            if(hit<T.size())
            {
                if(current[S[i]]<expected[S[i]])
                    hit++;
                current[S[i]]++;
            }
            while(hit == T.size() && start<S.size())
            {
                if((i-start+1)<min_window)
                {
                    min_window = i-start+1;
                    min_start = start;
                }
                current[S[start]]--;
                if(current[S[start]] < expected[S[start]])
                    hit--;
                start++;
                while(expected[S[start]]==0 && start<S.size())
                {
                    start++;
                }
            }
        }
        if(min_window==0x7fffffff) return "";
        return S.substr(min_start,min_window);
    }
};

int main()
{
    Solution* my_solution = new Solution();
    string S = "AB";
    string T = "B";
    string result = my_solution->minWindow(S, T);
    cout<<result<<endl;
}



