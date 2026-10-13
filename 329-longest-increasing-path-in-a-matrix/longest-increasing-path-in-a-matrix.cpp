class Solution {
public:
    int dfs(int i, int j,int prev_i,int prev_j, vector<vector<int>>& matrix, int n, int m,vector<vector<int>>& dp){
        if(i>=0 && i<n && j>=0 && j<m){
            if(matrix[prev_i][prev_j]<matrix[i][j]){
                if (dp[i][j] != -1) return dp[i][j];
                int a=dfs(i+1,j,i,j,matrix,n,m,dp);
                int b=dfs(i-1,j,i,j,matrix,n,m,dp);
                int c=dfs(i,j+1,i,j,matrix,n,m,dp);
                int d=dfs(i,j-1,i,j,matrix,n,m,dp); 

                dp[i][j]=max({a,b,c,d})+1; 
                return dp[i][j];      
            }
        }
        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        int maxlen=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int k=0; k<n*m; k++){
            int i=k/m;
            int j=k%m;
                int len = 1 + max({
                    dfs(i + 1, j, i, j, matrix, n, m,dp),
                    dfs(i - 1, j, i, j, matrix, n, m,dp),
                    dfs(i, j + 1, i, j, matrix, n, m,dp),
                    dfs(i, j - 1, i, j, matrix, n, m,dp)
                });
                maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};