#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<2) return n;
        int dup=0;
        int last = n;
        int current = A[0];
        for(int i=1;i<last;)
        {
            if(A[i]!=current)
            {
                current = A[i];
                i++;
                continue;
            }
            dup++;
            for(int j=i;j<last-1;j++)
            {
                A[j]=A[j+1];
            }
            last--;
            for(int k=0;k<last;k++)
                cout<<A[k]<<" ";
            cout<<endl;
        }
        return last;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here
    int A[]={1,2};
//solute your problem here
	int result = my_solution->removeDuplicates(A,2);

//print your output here
    cout<<"$$$$$$$$$$$$"<<endl;
    for(int i=0;i<result;i++)
        cout<<A[i]<<" ";
}
