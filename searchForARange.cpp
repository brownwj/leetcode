class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        result.push_back(left(A,n,target));
        result.push_back(right(A,n,target));
        return result;
    }
    
    int left(int A[], int n, int target)
    {
        if(n==0) return -1;
        int start=0;
        int end = n-1;
        int mid=(start+end)/2;
        while(end-start>1)
        {
            if(A[mid] >= target)
            {
                end=mid;
                mid=(start+end)/2;
            }
            else
            {
                start = mid;
                mid=(start+end)/2;
            }
        }
        if(A[start]!=target && A[end]!=target) return -1;
        if(A[end]==target && A[start]!=target) return end;
        return start;
    }
    int right(int A[], int n, int target)
    {
        if(n==0) return -1;
        int start=0;
        int end = n-1;
        int mid=(start+end)/2;
        while(end-start>1)
        {
            if(A[mid] > target)
            {
                end=mid;
                mid=(start+end)/2;
            }
            else
            {
                start = mid;
                mid=(start+end)/2;
            }
        }
        if(A[start]!=target && A[end]!=target) return -1;
        if(A[start]==target && A[end]!=target) return start;
        return end;
    }
};
