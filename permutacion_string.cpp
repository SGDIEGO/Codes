#include <bits/stdc++.h>

using namespace std;

void permutation(string &s, int c=0){
    if (c == s.size()) {
        cout << "s: " << s << '\n';
        return;
    }

    for(int i=c; i<s.size(); i++){
        swap(s[c], s[i]);
        permutation(s, c+1);
        swap(s[c], s[i]);
    }
}

void solve(){
    string s = "ABC";
    permutation(s);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}