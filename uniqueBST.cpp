class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=1) return 1;
        int result=0;
        for(int i=1;i<=n;i++)
        {
            result+=help(i-1,n-i,i);
        }
        return result;
    }
    int help(int m, int n,int current)
    {
        if(m<=1 && n<=1) return 1;
        if(m<=1)
        {
            int temp=0;
            for(int i=current+1;i<=current+n;i++)
                temp+=help(i-current-1,n-(i-current),i);
            return temp;
        }
        if(n<=1)
        {
            int temp=0;
            for(int i=current-1;i>=current-m;i--)
                temp+=help(m-(current-i),current-i-1,i);
            return temp;
        }
        else
        {
            int temp1=0;
            for(int i=current+1;i<=current+n;i++)
                temp1+=help(i-current-1,n-(i-current),i);
            int temp2=0;
            for(int i=current-1;i>=current-m;i--)
                temp2+=help(m-(current-i),current-i-1,i);
            return temp1*temp2;
        }
    }
};
