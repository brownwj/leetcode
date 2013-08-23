class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        int size=triangle.size();
        if(size==0) return 0;
        vector<int> dp;
        for(int i=0;i<size;i++)
            dp.push_back(0);
        for(int i=0;i<size;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(j==0) {continue;}
                else if(j==i) {dp[j]=dp[j-1];continue;}
                else
                {
                    dp[j]=dp[j-1]<dp[j]?dp[j-1]:dp[j];
                }
            }
            for(int j=i;j>=0;j--)
                dp[j]+=triangle[i][j];
        }
        int min = dp[0];
        for(int i=0;i<size;i++)
        {
            min = min<dp[i]?min:dp[i];
        }
        return min;
    }
};
