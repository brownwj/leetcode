class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==1) return 1;
        if(n==1) return 1;
        return help(m-1, n-1);
    }
    
    int help(int x, int y)
    {
        if(y<x)
        {
            int temp=y;
            y=x;
            x=temp;
        }
        y+=x;
        long long result=1;
        for(int i=0;i<x;i++)
        {
            result=result*(y-i)/(i+1);
        }
        return result;
    }
};
