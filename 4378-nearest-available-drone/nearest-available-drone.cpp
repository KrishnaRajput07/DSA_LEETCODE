class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans=INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0; i<drones.size(); i++){
            int x=drones[i][0];
            int y=drones[i][1];
            int range=drones[i][2];
            int distance=abs(x-target[0])+abs(y-target[1]);
            if(distance<=range){
                ans=min(ans,distance);
                if(mp.find(distance)==mp.end()) mp[distance]=i;
            }
        }
        if(ans==INT_MAX) return -1;
        return mp[ans];
    }
};