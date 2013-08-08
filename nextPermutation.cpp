#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()<=1) return;
        int i=0;
        for(;i<num.size()-1;i++)
        {
            if(num[i]<num[i+1])
                break;
        }
        if(i==num.size()-1)
        {
            sort(num.begin(),num.end());
            return;
        }
        i=num.size()-2;
        int smallest = num[num.size()-1];
        int k=-1;
        for(;i>=0;i--)
        {
            int j=i+1;
            for(;j<num.size();j++)
            {
                if(num[j]>num[i] && (k==-1 || num[k]>num[j]))
                {
                    k=j;
                }
            }
            if(k!=-1)
                break;
        }
        int temp;
        temp = num[i];
        num[i] = num[k];
        num[k] = temp;
        vector<int>::iterator iter = num.begin();
        cout<<i<<endl;
        for(int j=0;j<=i;j++)
            iter++;
        cout<<"*iter = "<<*iter<<endl;
        sort(iter, num.end());
        return;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here

//solute your problem here
    int array[] = {1,3,2};
    vector<int> num(array,array+sizeof(array)/sizeof(int));
	my_solution->nextPermutation(num);

//print your output here
    for(int i=0;i<num.size();i++)
        cout<<num[i]<<" ";
    cout<<endl;
}
