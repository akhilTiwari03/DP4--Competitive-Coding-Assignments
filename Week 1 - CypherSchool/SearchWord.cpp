#define max_dir 4;
class Solution {
public:
    bool isSafe(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, const int &r, const int &c, string& word, int idx){
        
        if(x>=0 && x<r && y>=0 && y<c && !visited[x][y] && board[x][y] == word[index])
    }

    public : int xm[] {0,0,1,-1};
    public : int ym[] {1,-1,0,0};

    bool exists(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, const int &r, const int &c, string& word, int idx){
        if(index >= word.size())
            return true;
        else{
            visited[x][y] = true;
            for(int i=0; i<max_dir; i++){
                int nextX = x + xm[i];
                int nextY = y + ym[i];
                if(isSafe(board, visited, nextX, nextY, r, c, word, idx+1)){
                    if(exists(board, visited, nextX, nextY, r, c, word, idx+1))
                        return true;
                }
            }
            // backtracking step
            visited[x][y] = false;
            return false;
        }
        if(isSafe(visited, x, y, r, c, word, idx))
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "")
            return true;
        int r = board.size();
        if(r==0)
            return false;
        int c = board[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == word[0]){
                    if(exists(board, visited, i, j, r, c, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};