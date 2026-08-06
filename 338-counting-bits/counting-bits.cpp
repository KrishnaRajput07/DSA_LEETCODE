class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0; i<=n; i++){
            int c=0;
            int x=i;
            while(x){
               x=x&(x-1);
               c++; 
            }
            ans[i]=c;
        }
        return ans;
    }
};