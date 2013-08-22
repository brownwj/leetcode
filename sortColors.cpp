class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start=0,end=n-1;
        while(start<end)
        {
            if(A[start]==0 || A[start]==1)
            {start++;continue;}
            else if(A[end]==2)
            {end--;continue;}
            A[start]=A[end];
            A[end]=2;
            start++;
            end--;
        }
        if(A[start]==2 && start!=0) start--;
        end = start;
        start=0;
        while(start<end)
        {
            if(A[start]==0) {start++;continue;}
            else if(A[end]==1) {end--;continue;}
            else
            {
                A[start]=0;A[end]=1;
                start++;end--;
            }
        }
        return;
    }
};
