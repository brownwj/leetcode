class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size()==0) return false;
        int row=0;
        int tag=0;
        while(row<matrix.size())
        {
            if(target==matrix[row][0])
            {
                return true;
            }
            if(target> matrix[row][0])
            {
                tag=1;
            }
            if(target < matrix[row][0] && tag==1)
            {
                tag=2;break;
            }
            row++;
        }
        return binary(matrix[row-1],target);
    }
    
    bool binary(vector<int> vec, int target)
    {
        int length = vec.size();
        int start =0;
        int end = length-1;
        int mid = (start+end)/2;
        while(end-start>1)
        {
            if(vec[mid]>target)
            {
                end = mid;
                mid = (start+end)/2;
            }
            else if(vec[mid]<target)
            {
                start = mid;
                mid = (start+end)/2;
            }
            else
            {
                return true;
            }
        }
        return vec[start]==target || vec[end]==target;
    }
};
