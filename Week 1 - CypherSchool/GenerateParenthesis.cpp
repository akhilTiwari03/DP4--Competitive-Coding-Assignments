#include <bits/stdc++.h>
using namespace std;
void generate(string& curr, vector<string>& result, int o, int c, int n){
        if(c == n){ 
            result.push_back(curr);
            return;
        }
        if(o < n)
            generate(curr, result, o+1, c, n);
        if(c < 0)
            generate(curr, result, o, c+1, n);
    }
    vector<string> generateParenthesis(int n) {
        // if you use more clos par then open par then it is wrong
        vector<string> result;
        string curr = "";
        generate(curr, result, 0, 0, n);
        // returning the desired outut vector
        return result;
    }
int main(){
    int n = 3;
    vector<string> vec = generateParenthesis(n);
    // copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    for(auto i : vec)
        cout<<i<<" Hello "<<endl;
}