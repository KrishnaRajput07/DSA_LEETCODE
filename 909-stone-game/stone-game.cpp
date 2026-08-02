class Solution {
public:
int helper(int l,int r,vector<int>& piles,vector<vector<int>>& dp){
    if(l==r) return piles[l];

    if(dp[l][r]!=-1) return dp[l][r];
    return dp[l][r]=max(
        piles[l]-helper(l+1,r,piles,dp),
        piles[r]-helper(l,r-1,piles,dp)
    );
}
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
     return (helper(0,piles.size()-1,piles,dp)>0);
    }
};