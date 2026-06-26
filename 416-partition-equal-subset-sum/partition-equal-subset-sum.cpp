class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto els:nums){
            sum+=els;
        }
        if(sum%2!=0) return false;
        vector<vector<bool>> dp(nums.size(),vector<bool>((sum/2)+1,false));
        //base case 
        for(int i=0; i<nums.size(); i++) dp[i][0]=true;
        if(nums[0] <= sum/2)dp[0][nums[0]] = true;

        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<=sum/2; j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j){
                    take =dp[i-1][j-nums[i]];
                }
                dp[i][j]=nottake||take;
            }
        }
        return dp[nums.size()-1][sum/2];
    }
};