class Solution {
public:
    bool check(long long sum,int x){
        if(sum==0) return x==0;
        int last=sum%10;
        while(sum>=10){
            sum/=10;
        }
        int first=sum%10;
        return ((first==x)&&(last==x));
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            long long sum=0;
            for(int j=i; j<nums.size(); j++){
                sum+=nums[j];
                if(check(sum,x)) cnt++;
            }
        }
        return cnt;
    }
};