#include <bits/stdc++.h>
using namespace std;
void rec(string s, int l, int e){
    if(l == e){
        cout<<s<<endl;
        return;
    }
    for(int i=l; i<=e; i++){
        swap(s[i], s[l]);
        rec(s, l+1, e);
        swap(s[i], s[l]);
    }
}
void permute(string& s){
    rec(s, 0, s.length()-1);
}
int main(){
    string s = "abcd";
    permute(s); // function call
    return 0;
}