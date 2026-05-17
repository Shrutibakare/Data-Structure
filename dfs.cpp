#include <iostream>
using namespace std;

int graph[5][5] = {
    {0,1,1,0,0},
    {1,0,0,1,1},
    {1,0,0,0,0},
    {0,1,0,0,0},
    {0,1,0,0,0}
};

bool visited[5] = {false};

void dfs(int node) {
    visited[node] = true;

    cout << node << " ";

    for(int i = 0; i < 5; i++) {
        if(graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {

    cout << "DFS Traversal: ";
    dfs(0);

    return 0;
}