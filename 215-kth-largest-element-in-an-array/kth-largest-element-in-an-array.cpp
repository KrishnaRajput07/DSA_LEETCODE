class Solution {
public:
    int count(int i,vector<int>& nums){
        int cnt=0;
        for(auto it: nums){
            if(it>=i) cnt++;
        }
        return cnt;
    }
    int findKthLargest(vector<int>& nums, int k) {
       int maxi=INT_MIN;
       int mini=INT_MAX;
       for(int i=0; i<nums.size(); i++){
          mini=min(mini,nums[i]);
          maxi=max(maxi,nums[i]);
       } 
       int low=mini;
       int high=maxi;
       while(low<=high){
          int mid=(high+low)/2;
          int val=count(mid,nums);
          if(val>=k){
            low=mid+1;
          }
          else{
            high=mid-1;
          }
       }
       return high;
    }
};