class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> visi(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        queue<pair<pair<pair<int,int>,int>,int>> q;
        q.push({{{0,0},k},0});
        visi[0][0][k]=1;

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        while(!q.empty()){
            auto cell=q.front();
            int row=cell.first.first.first;
            int col=cell.first.first.second;
            int krem=cell.first.second;
            int step=cell.second;
            q.pop();

            if(row==m-1 && col==n-1){
                return step;
            }
            for(int i=0; i<4; i++){
                int nx=row+dx[i];
                int ny=col+dy[i];

                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int newK=krem;
                    if(grid[nx][ny]==1){
                       newK--;
                    }
                    if(newK<0) continue; // so that we do not access vis[][][-1]
                    if(visi[nx][ny][newK] != -1)continue;

                visi[nx][ny][newK] = 1;

                q.push({{{nx, ny}, newK}, step+1});
                }
            }
        }
        return -1;
    }
};