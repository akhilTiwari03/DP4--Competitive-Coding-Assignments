#include <bits/stdc++.h>
using namespace std;
vector<string> dialpad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void rec(string& digits, vector<string>& result, string s, int i, int n){
    if(i == n){
        result.push_back(s);
        return;
    }
    char dig = digits[i];
    string possible = dialpad[dig-'0'];
    for(int j=0; j<possible.size(); j++)
        rec(digits, result, s+possible[j], i+1, n);
}
vector<string> letterCombinations(string digits) {
    vector<string> result;
    int n = digits.length();
    if(n<1)
        return result;
    string s = "";
    rec(digits, result, s, 0, n);
    return result;
}
int main(){

}
/*

*/