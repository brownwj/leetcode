class Solution {
private:
    vector<int> result;
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        if(matrix.size()==0) return result;
        int m = matrix.size();
        int n = matrix[0].size();
        getPartial(matrix, 0, 0, m, n);
        return result;
    }
    
    void getPartial(vector<vector<int> > &matrix, int x, int y, int m, int n)
    {
        if(m-2*x <1 || n-2*y<1) return;
        if(m-2*x == 1)
        {
            for(int i=y;i<=n-y-1;i++)
                result.push_back(matrix[x][i]);
            return;
        }
        else if(n-2*y == 1)
        {
            for(int i=x;i<=m-x-1;i++)
                result.push_back(matrix[i][y]);
            return;
        }
        else
        {
            for(int i=y;i<n-y-1;i++)
                result.push_back(matrix[x][i]);
            for(int i=x;i<m-x-1;i++)
                result.push_back(matrix[i][n-y-1]);
            for(int i=n-y-1;i>y;i--)
                result.push_back(matrix[m-x-1][i]);
            for(int i=m-x-1;i>x;i--)
                result.push_back(matrix[i][y]);
            getPartial(matrix, x+1, y+1, m, n);
            return;
        }
    }
};
