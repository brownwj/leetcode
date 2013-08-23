class Solution {
    public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m==0||n==0) return 0;
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int> > dp;
        for(int i=0;i<m;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
                temp.push_back(0);
            dp.push_back(temp);
        }   
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (obstacleGrid[i][j]==0){
                    if (i==0 && j==0) dp[i][j] = 1;
                    else dp[i][j] = (i>0 ? dp[i-1][j] : 0) + (j>0 ? dp[i][j-1] : 0);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
