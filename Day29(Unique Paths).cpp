class Solution {
public:
    int maze[1005][1005];
    int uniquePaths(int m, int n){
        //dfs(m,n,i,j);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) maze[i][j]=0;
        return countPaths(m,n);
    }
    int countPaths(int R,int C){
    if (maze[0][0]==-1) 
        return 0; 
    for (int i=0; i<R; i++) 
    { 
        if (maze[i][0] == 0) 
            maze[i][0] = 1; 
        else
            break; 
    } 
    for (int i=1; i<C; i++) 
    { 
        if (maze[0][i] == 0) 
            maze[0][i] = 1; 
        else
            break; 
    }
    for (int i=1; i<R; i++) 
    { 
        for (int j=1; j<C; j++) 
        { 
            if (maze[i][j] == -1) 
                continue;
            if (maze[i-1][j] > 0) 
                maze[i][j] = (maze[i][j] + maze[i-1][j]); 
            if (maze[i][j-1] > 0) 
                maze[i][j] = (maze[i][j] + maze[i][j-1]); 
        } 
    } 
    return (maze[R-1][C-1] > 0)? maze[R-1][C-1] : 0; 
} 
  
    /*void dfs(int m,int n,int i,int j){
        if(i==m && j==n){ count++; return;}
        else if(i==m) dfs(m,n,i,j+1);
        else if(j==n) dfs(m,n,i+1,j);
        else{
            dfs(m,n,i+1,j);
            dfs(m,n,i,j+1);
        }*/
};
