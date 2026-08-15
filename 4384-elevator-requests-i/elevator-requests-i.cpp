class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int t=requests[0];
        for(int i=1; i<requests.size(); i++){
            t+=abs(requests[i-1]-requests[i]);
        }
        return t;
    }
};