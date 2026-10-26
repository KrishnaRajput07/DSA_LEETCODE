class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            int x=p.first;
            int y=p.second;
            q.pop();
            int dx[]={1,0,-1,0};
            int dy[]={0,1,0,-1};
            for(int i=0; i<4; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny]==-1){
                    mat[nx][ny]=mat[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return mat;
    }
};