class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visi(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    visi[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        int time=0;
        while(!q.empty()){
            auto row=q.front().first.first;
            auto col=q.front().first.second;
            time   =q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow<m && ncol<n && nrow>=0 && ncol>=0 && grid[nrow][ncol]==1 && visi[nrow][ncol]!=1){
                    visi[nrow][ncol]=1;
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    time=-1;
                }
            }
        }
        return time;
    }
};