class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for (int i=0; i<n; i++) {
            dp[i][i]=nums[i];
        }

        for (int len=2; len<=n; len++) {
            for (int l=0; l+len-1<n; l++) {
                int r = l + len - 1;
                int left = nums[l] - dp[l + 1][r];
                int right = nums[r] - dp[l][r - 1];
                dp[l][r] = max(left, right);
            }
        }
        return dp[0][n-1]>=0;
    }
};