class Solution {
public:
    int find_range(int num){
        int maxi=INT_MIN;
        int mini=INT_MAX;
        while(num){
            maxi=max(maxi,num%10);
            mini=min(mini,num%10);
            num=num/10;
        }
        return maxi-mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxi=-1;
        int sum=0;
        for(auto el:nums){
            int x=find_range(el);
            if(maxi<x){
                sum=el;
                maxi=max(maxi,x);
            }
            else if(maxi==x){
                sum+=el;
            }
            else{ 
                continue;
            }
        }
        return sum;
    }
};