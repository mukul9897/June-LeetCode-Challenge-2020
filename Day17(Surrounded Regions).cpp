class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(!board.empty()){
            int l1=board.size(),l2=board[0].size();
            if(l1<=2) return;
            if(l2<=2) return;
            for(int i=0;i<l1;i++){
                for(int j=0;j<l2;j++){
                    if(board[i][j]=='O' && (i==0 || i==l1-1 || j==0 || j==l2-1)) 
                        dfs(board,i,j);
                }
            }
             for(int i=0;i<l1;i++){
                for(int j=0;j<l2;j++){
                    if(board[i][j]=='O') board[i][j]='X';
                    else if(board[i][j]=='A') board[i][j]='O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i>=0 && i<board.size() && j>=0 && j<board[0].size() && board[i][j]=='O'){
            board[i][j]='A';
            dfs(board,i+1,j);
            dfs(board,i-1,j);
            dfs(board,i,j+1);
            dfs(board,i,j-1);
        }
    }
};
