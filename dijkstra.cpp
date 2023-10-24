#include <bits/stdc++.h>

using namespace std;

// a=node, b=distance
#define p(a, b) pair<int, float>(a, b)
#define foreach(i, array) for(auto& i : array)

void solve(){
    vector<vector<pair<int, float>>> graph = {
        {p(1, 5), p(2, 2)},
        {p(0, 5), p(2, 6),p(3, 5)},
        {p(0, 2),p(1, 6),p(3, 8),p(4, 10)},
        {p(1, 5),p(2, 8),p(4, 2),p(5, 6)},
        {p(2, 10),p(3, 2),p(5, 2)},
        {p(3, 6),p(4, 2)},
    };
    int nodes = graph.size();
    vector<float> distances(nodes, MAXFLOAT);
    vector<bool> walk(nodes, false);
    int init = 0, end=5, current=init;
    distances[init] = 0;

    while(current != end){
        cout << "current: " << current << '\n';
        walk[current] = true;
        float min_d = MAXFLOAT;
        int node_min;
        // Recorrer adyacentes
        foreach(node, graph[current]){
            int &adj = node.first; // Adjacent node
            float &dist = node.second; // Distance between current node and adjacent node

            // If node has not been traversed
            if(!walk[adj]){
                // Have minimum distance
                distances[adj] = min(distances[current]+dist, distances[adj]);
                // Find the minimum node
                if(distances[adj]<min_d) {min_d = distances[adj]; node_min = adj;}
            }
        }
        // Get next node
        current = node_min;
    }
    cout << "current: " << end << '\n';
    foreach(d, distances) cout << d << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}