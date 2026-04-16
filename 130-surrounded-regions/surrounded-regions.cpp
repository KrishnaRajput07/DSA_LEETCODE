class Solution {
public:
 void dfs(vector<vector<char>>& board,vector<vector<int>>& visi,int x,int y){
    int m=board.size();
    int n=board[0].size();

    visi[x][y]=1;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    for(int i=0; i<4; i++){
        int newX=x+dx[i];
        int newY=y+dy[i];
        if(newX>=0 && newY>=0 && newX<m && newY<n && board[newX][newY]=='O' && visi[newX][newY]!=1){
            dfs(board,visi,newX,newY);
        }
    }
 }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visi(m,vector<int>(n,0));
        // for rows
        for(int j = 0; j < n; j++){
           if(board[0][j] == 'O' && !visi[0][j]) dfs(board, visi, 0, j);
           if(board[m-1][j] == 'O' && !visi[m-1][j]) dfs(board, visi, m-1, j);
        }
       // for coloumns
        for(int i = 0; i < m; i++){
           if(board[i][0] == 'O' && !visi[i][0]) dfs(board, visi, i, 0);
           if(board[i][n-1] == 'O' && !visi[i][n-1]) dfs(board, visi, i, n-1);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visi[i][j]!=1 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};