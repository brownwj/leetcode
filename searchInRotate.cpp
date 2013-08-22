#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return -1;
        if(n==1)
        {
            if(target==A[0]) return 0;
            else return -1;
        }
        int end=0;
        while(end<n-1)
        {
            if(A[end]>A[end+1]) break;
            end++;
        }
        if(end==n-1) return binary(A,n,target);
        int left = binary(A,end+1,target);
        int right = binary(&A[end+1],n-1-end,target);
        if(right!=-1) right = right+end+1;
        if(left!=-1) return left;
        if(right!=-1) return right;
        return -1;
    }
    
    int binary(int A[], int n, int target)
    {
        if(n==0) return -1;
        int start=0,end=n-1,mid=(start+end)/2;
        while(end-start>1)
        {
            if(A[mid] < target)
            {
                start=mid;
                mid=(start+end)/2;
            }
            else if(A[mid] > target)
            {
                end = mid;
                mid = (start+end)/2;
            }
            else
            {
                return mid;
            }
        }
        if(A[start]==target) return start;
        if(A[end]==target) return end;
        return -1;
    }
};


int main()
{
	Solution* my_solution = new Solution();
//declare and generate your input here
    int A[] = {1,3,5};
//solute your problem here
	int result = my_solution->search(A,3,4);

//print your output here
    cout<<result<<endl;
}
