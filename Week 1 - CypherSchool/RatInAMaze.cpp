#include <bits/stdc++.h>
using namespace std;
#define max_directions 4
// 1--> I can go from it.
// 0--> I can't go from it.
int xM[] = {0, 0, 1, -1};
int yM[] = {1, -1, 0, 0};
bool isSafe(vector<vector<int>>& mat, vector<vector<bool>>& reached, int r, int c, int x, int y){
    if(reached[x][y]==0 || mat[x][y]==1 || x<0 || y<0 || x==r || y==c)
        return false;
    return true;    
}
bool path(vector<vector<int>>& mat, vector<vector<bool>>& reached, int r, int c, int x, int y){
    // base condition
    if(x==r-1 && y==c-1 && mat[r-1][c-1]==1){
        reached[x][y] = true;
        return true;
    }
    if(isSafe(mat, reached, r, c, x, y)){
        reached[x][y] = true;
        for(int i=0; i<max_directions; i++){
            if(path(mat, reached, r, c, x+xM[i], y+yM[i]))
                return true;
        }
        reached[x][y] = false;
    }
    return false;
}
bool rat_in_maze(vector<vector<int>> mat){
    int r = mat.size();
    if(r==0)
        return true;
    int c = mat[0].size();
    vector<vector<bool>> reached(r, vector<bool>(c, false));
    return path(mat, reached, r, c, 0, 0);
}
int main(){
    vector<vector<int>> mat = {{1,1,1,1},
                               {1,1,0,1},
                               {0,0,1,1},
                               {0,0,1,1}};
    
    cout<<rat_in_maze(mat)<<endl;
}