#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> m;
        if(num.size()==0) return 0;
        int size = num.size();
        int result=1;
        for(int i=0;i<size;i++)
            m.insert(pair<int,int>(num[i],1));
        int tag=0,start,pre;
        map<int, int>::iterator it;
        for(it=m.begin();it!=m.end();it++)
            cout<<it->first<<" ";
        cout<<endl;
        for(it=m.begin();it!=m.end();it++)
        {
            if(tag==0)
            {
                tag=1;
                start=it->first;
                pre=start;
                continue;
            }
            if(it->first==pre+1)
            {
                pre++;
            }
            else
            {
                tag=1;
                result=result>(pre-start+1)?result:(pre-start+1);
                start=it->first;
                pre=start;
            }
        }
        if(tag==1) result=result>(pre-start+1)?result:(pre-start+1);
        return result;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here
    int a[]={9,1,4,7,3,-1,0,5,8,-1,6};
    vector<int> b(a,a+11);
//solute your problem here
	int result = my_solution->longestConsecutive(b);

//print your output here
    cout<<result<<endl;
}
