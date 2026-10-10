class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int>mp;
        for(auto el:nums){
            mp[el]++;
        }
        for(int i=0; i<nums.size(); i++){
            int x=nums[i];
            if(mp[x]==1){
                if(!mp[x-1] && !mp[x+1]){
                    ans.push_back(nums[i]);
                }
            }
            else{
                continue;
            }
        }
        return ans;
    }
};