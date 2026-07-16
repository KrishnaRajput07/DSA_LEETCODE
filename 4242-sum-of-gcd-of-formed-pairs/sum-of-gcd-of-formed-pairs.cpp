class Solution {
public:
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a,a);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGcd(n);
        int mx=nums[0];
        for(int i=0; i<n; i++){
            mx=max(mx,nums[i]);
            prefixGcd[i]=gcd(nums[i],mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());

        long long sumGcd=0;
        int i=0;
        int j=n-1;
        while(j>i){
            sumGcd+=gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return sumGcd;
    }
};