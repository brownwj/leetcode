class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return false;
        if(n==1)
        {
            if(target==A[0]) return true;
            else return false;
        }
        int end=0;
        while(end<n-1)
        {
            if(A[end]>A[end+1]) break;
            end++;
        }
        if(end==n-1) return binary(A,n,target);
        bool left = binary(A,end+1,target);
        bool right = binary(&A[end+1],n-1-end,target);
        return left || right;
    }
    
    bool binary(int A[], int n, int target)
    {
        if(n==0) return false;
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
                return true;
            }
        }
        if(A[start]==target) return true;
        if(A[end]==target) return true;
        return false;
    }
};
