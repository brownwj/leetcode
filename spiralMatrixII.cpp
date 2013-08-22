class Solution {
private:
    vector<vector<int> > result;
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        if(n<=0) return result;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
                temp.push_back(0);
            result.push_back(temp);
        }
        getCircle(0,1,n);
        return result;
    }
    
    void getCircle(int x, int start, int n)
    {
        if(2*x+1 == n) {result[x][x]=n*n; return; }
        if(2*x+1 > n) return;
        for(int i=x;i<n-x-1;i++)
            result[x][i]=start++;
        for(int i=x;i<n-x-1;i++)
            result[i][n-x-1]=start++;
        for(int i=n-x-1;i>x;i--)
            result[n-x-1][i]=start++;
        for(int i=n-x-1;i>x;i--)
            result[i][x]=start++;
        getCircle(x+1, start, n);
    }
};
