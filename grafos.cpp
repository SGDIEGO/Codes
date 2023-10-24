#include <functional>
#include <iostream>

using namespace std;
const int nodos = 5;

int main(){
    srand(time(0)); 

    float grafo[nodos][nodos];
    bool w_nodo[nodos];

    // Create graph
    for(int i=0; i<nodos; i++)
        for (int j=i; j<nodos; j++)
            grafo[i][j] = grafo[j][i] = (i==j) ? 0 : (rand()+10)%100;
    
    // Show graph
    for(int i=0; i<nodos; i++){
        for (int j=0; j<nodos; j++) cout << grafo[i][j] << '\t';
        cout << '\n';
    }
    
    // Initialize nodes as not walkthrough
    for(int i=0; i<nodos; i++) w_nodo[i] = false;

    function<void(int)> dfs = [&](int node){
        for(int i=0; i<nodos; i++)
            if(!w_nodo[i]){
                cout << grafo[node][i] << '\n';
                break;
            }
    };

    for(int i=0;i<nodos;i++){
        w_nodo[i] = true;
        dfs(i);
    }
}