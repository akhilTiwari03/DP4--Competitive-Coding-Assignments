#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        int  vis[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int time = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        cout<<"While"<<endl;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for(int i=0; i<4; i++){
                int nr = r+delrow[i];
                int nc = c+delrow[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && 
                        vis[nr][nc]!=1 && grid[nr][nc]==1){
                    q.push({{nr, nc}, t+1});
                }
            }
            cout<<"Hii"<<endl;
        }
        cout<<"Last"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 1 && grid[i][j]==1)
                    return -1;
            }
        }
        cout<<"Hii Shubham"<<endl;
        return time;
    }

    int main(){
        vector<vector<int>> vec = {{2,1,1},
                                    {1,1,1},
                                    {0,1,1}};
        cout<<"In main"<<endl;
        cout<<orangesRotting(vec)<<endl;
    }