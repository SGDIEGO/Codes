#include <bits/stdc++.h>

using namespace std;

void subset(int array[], int i, int max, int N, int& T){
    if (N < max) return;
    T++;

    for(int pos=i; pos < max; pos++) cout << array[pos] << '\t';

    cout << '\n';
    subset(array, i, max+1, N, T);
}

void solve(){
    int N = 5;
    int array[] = {1,2,3, 4, 5};
    int t=0;

    for (int i=0; i<N; i++) subset(array, i, 1, N, t);
    cout << t;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}