class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=matrix.size();
        if(i<2) return;
        for(int j=0;j<i;j++)
            help(matrix, j);
    }
    
    void help(vector<vector<int> > &matrix, int m)
    {
        int n = matrix.size();
        if(2*m+1 == n) return;
        for(int x=m;x<n-m-1;x++)
        {
            int temp = matrix[m][x];
            
            matrix[m][x] = matrix[n-x-1][m];
            matrix[n-x-1][m] = matrix[n-m-1][n-1-x];
            matrix[n-m-1][n-1-x] = matrix[x][n-m-1];
            matrix[x][n-m-1] = temp;
        }
        return; 
    }
};
