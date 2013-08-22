#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        int start=0,end=n-1;
        int mid=(start+end)/2;
        while(end-start>1)
        {
            if(A[mid]>target)
            {
                end=mid;
                mid=(start+end)/2;
            }
            else if(A[mid]<target)
            {
                start=mid;
                mid=(start+end)/2;
            }
            else
            {
                return mid;
            }
        }
        if(A[start]==target) return start;
        if(A[end]==target) return end;
        if(A[start]>target) return start;
        if(A[end]<target) return end+1;
        return end;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here
    int A[]={1,3};
//solute your problem here
	int result =my_solution->searchInsert(A,2,0);

//print your output here
    cout<<result<<endl;
}
