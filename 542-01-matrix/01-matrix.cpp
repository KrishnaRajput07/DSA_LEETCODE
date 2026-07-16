class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        int visi[m][n];
        vector<vector<int>>dist(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visi[i][j]=1;
                    dist[i][j]=0;
                }
                else{
                    visi[i][j]=0;
                }
            }
        }
            int dx[4]={0,1,0,-1};
            int dy[4]={-1,0,1,0};
            int d;
            while(!q.empty()){
                auto p=q.front();
                int x=p.first.first;
                int y=p.first.second;
                d=p.second;
                dist[x][y]=d;
                q.pop();
                for(int i=0; i<4; i++){
                    int newX=x+dx[i];
                    int newY=y+dy[i];
                    if(newX>=0 && newX<m && newY>=0 && newY<n && visi[newX][newY]==0){
                        visi[newX][newY]=1;
                        q.push({{newX,newY},d+1});
                    }
                }
            
        }
        return dist;
    }
};