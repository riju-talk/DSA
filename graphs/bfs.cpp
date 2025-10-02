#include <bits/stdc++.h>
using namespace std;

void bfs(map<int, vector<int>>& graph){
    set<int> visited;
    queue<int> q;
    auto firstelt = graph.begin();
    int temp = firstelt->first;
    q.push(temp);
    visited.insert(temp);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout  << node << "|";
        for(int a: graph[node]){
            if(visited.count(a)) continue;
            q.push(a);
            visited.insert(a);
        }
    }
}

int main() {
    map<int, vector<int>> graph;

    // Undirected Graph Example:
    graph[1] = {2, 3};
    graph[2] = {1, 4};
    graph[3] = {1, 4, 5};
    graph[4] = {2, 3, 5};
    graph[5] = {3, 4, 6};
    graph[6] = {5};

    // Print the adjacency list
    for (auto &p : graph) {
        cout << p.first << " -> ";
        for (int v : p.second) {
            cout << v << " ";
        }
        cout << "\n";
    }
    bfs(graph);
    return 0;
}
