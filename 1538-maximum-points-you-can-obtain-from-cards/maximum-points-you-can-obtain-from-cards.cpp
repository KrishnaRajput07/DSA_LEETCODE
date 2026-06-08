class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0;
        int rsum=0;
        for(int i=0; i<k; i++){
            lsum+=cardPoints[i];
        }
        int sum=lsum;
        int i=k-1;
        for(int j=n-1; j>=n-k; j--){
            rsum+=cardPoints[j];
            if(i>=0){
                lsum-=cardPoints[i];
                i--;
            }
            sum=max(sum,lsum+rsum);
        }
        return sum;
    }
};