class Solution {
public:
    bool static comp(vector<int>& p1,vector<int>& p2){
        if(p1[1]==p2[1]) return p1[0]<p2[0];
        return p1[1]<p2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        int n=intervals.size();
        int j=1;
        int i=0;
        while(j<n && i<j){
            if(intervals[i][1]>intervals[j][0]) { // if overlapping i remain same , j always incremnet 
                cnt++;
            }
            else{ // no overlap
                i=j;
            }   
             j++;
        }
        return cnt;
    }
};