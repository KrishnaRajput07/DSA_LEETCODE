class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visi, int i){
        visi[i]=1;
        for(auto it:adj[i]){
            if(visi[it]==0){
                dfs(adj,visi,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(); // no of vertices

        //making of adjacency list
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visi(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(visi[i]==0){
                cnt++;
                dfs(adj,visi,i);
            }
        }
        return cnt;
    }
};