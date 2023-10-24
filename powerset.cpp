#include <bits/stdc++.h>

using namespace std;

const char alphabet[] = {'a', 'b'};

vector<vector<vector<int>>> table = {
    {{0,1}, {0}},
    {{}, {2}},
    {{}, {}}
};

void solve(){
    set<vector<int>> q_ = {{0}};
    vector<vector<vector<int>>> table_;

    for(int i=0; i < q_.size(); i++){
        table_.push_back(vector<vector<int>>(sizeof(alphabet)));
        set<vector<int>>::iterator it = q_.begin();
        advance(it, i);

        for(auto& s : *it){
            for(int a=0; a<sizeof(alphabet); a++) {
                vector<int>::iterator it;
                for (auto& b : table[s][a]){
                    it = find(table_[i][a].begin(), table_[i][a].end(), b);
                    if(it == table_[i][a].end()) table_[i][a].push_back(b);
                } 
                q_.insert(table_[i][a]);
            }
        }
    }
    for (int state=0; state < table_.size(); state++){
        set<vector<int>>::iterator it = q_.begin();
        advance(it, state);
        for(int i=0; i<table_[state].size(); i++){
            cout << "{";
            for(auto& s : *it) cout << s << ",";
            cout << "},"<<alphabet[i]<<": ";
            for(auto& s_ : table_[state][i]) cout <<  s_ << " ";
            cout << '\n';
        }
    }
}

int main(){
    solve();
}