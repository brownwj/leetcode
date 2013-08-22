#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int A[10] = {1,1,2,6,24,120,720,5040,40320,362880};
        string result="";
        if(k>A[n]) return result;
        if(n==1) return "1";
        k=k-1;
        int bit_no = n;
        map<int, bool> used;
        stringstream ss;
        for(int i=1;i<10;i++)
            used.insert(pair<int,bool>(i,false));
        while(bit_no!=0)
        {
            int seq = (k)/A[bit_no-1]+1;
            k = (k)%A[bit_no-1];
            int accumulate=-1;
            int i=0;
            while(accumulate<seq)
            {
                if(used[i]==false)
                    accumulate++;
                if(accumulate == seq)
                {
                    ss.clear();
                    ss<<result;
                    ss<<i;
                    ss>>result;
                    used[i]=true;
                    bit_no--;
                }
                i++;
            }
        }
        return result;
    }
};

int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here

//solute your problem here
	string result = my_solution->getPermutation(3,3);

//print your output here
    cout<<result<<endl;
}
