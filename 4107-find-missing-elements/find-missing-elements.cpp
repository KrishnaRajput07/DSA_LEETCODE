class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        vector<int>freq (maxi+1,0);
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        for(int i=mini; i<=maxi; i++){
            if(freq[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};