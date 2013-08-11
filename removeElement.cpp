class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int last = n;
        int i=0;
        while(i<last)
        {
            if(A[i]==elem)
            {
                int temp = A[i];
                A[i] = A[last-1];
                A[last-1] = temp;
                last--;
            }
            else
            {
                i++;
            }
        }
        return last;
    }
};
