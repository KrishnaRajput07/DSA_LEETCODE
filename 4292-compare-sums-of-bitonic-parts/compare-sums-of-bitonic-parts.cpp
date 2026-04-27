class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        long long sumL=nums[0];
        long long sumR=nums[n-1];
        long long peak;
        for(int i=1; i<n-1; i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){ 
                peak=nums[i];
                sumL+=nums[i];
                sumR+=nums[i];
            }
            else if(nums[i]>nums[i-1]){
                sumL+=nums[i];
            }
            else{
                sumR+=nums[i];
            }
        }
        if(sumL>sumR) return 0;
        else if(sumL<sumR) return 1;
        return -1;
    }
};