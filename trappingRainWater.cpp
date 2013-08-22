class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<3) return 0;
        int i=1;
        int result=0;
        for(;i<n-1;i++)
        {
            result+=getCurrent(A,n,i);
        }
        return result;
    }

    int getCurrent(int A[], int n, int i)
    {
        int k=i-1;
        int left=A[i];
        for(;k>=0;k--)
        {
            if(A[k]>left)
                left=A[k];
        }
        k=i+1;
        int right=A[i];
        for(;k<n;k++)
        {
            if(A[k]>right)
                right=A[k];
        }
        if(left>A[i] && right>A[i])
            return (left<right)?(left-A[i]):(right-A[i]);
        return 0;
    }
};
