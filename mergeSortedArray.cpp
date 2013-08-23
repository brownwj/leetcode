class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=m-1,j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(A[i]>B[j])
            {
                A[k]=A[i];
                k--;
                i--;
            }
            else
            {
                A[k]=B[j];
                k--;
                j--;
            }
        }
        if(i==-1)
        {
            for(;j>=0;j--)
            {
                A[k]=B[j];
                k--;
            }
        }
        return;
    }
};
