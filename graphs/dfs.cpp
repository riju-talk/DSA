#include <bits/stdc++.h>
using namespace std;

void dfs_recursive(map<int,vector<int>>& graph, int node, set<int> &visited){
    visited.insert(node);
    cout << node << "->" << "";
    for(int a: graph[node]){
        if(visited.count(a)) continue;
        visited.insert(a);
        dfs_recursive(graph, a, visited);
    }
}

void dfs_iterative(map<int, vector<int>>& graph, stack<int>& s, set<int>& visited) {
    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (visited.count(node)) continue; // If already visited, skip

        cout << node << "->" << ""; // Process the node
        visited.insert(node);

        // Push neighbors in reverse order to maintain correct DFS order
        for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
            if (!visited.count(*it)) {
                s.push(*it);
            }
        }
    }
}


int main() {
    map<int, vector<int>> graph;
    graph[1] = {2, 3};
    graph[2] = {1, 4};
    graph[3] = {1, 4, 5};
    graph[4] = {2, 3, 5};
    graph[5] = {3, 4, 6};
    graph[6] = {5};

    for (auto &p : graph) {
        cout << p.first << " -> ";
        for (int v : p.second) {
            cout << v << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
    set<int> visited;
    stack<int> s;
    cout << "Recursive DFS" << "\n";
    dfs_recursive(graph, 1, visited);
    cout << "\n" << "Iterated DFS" << "\n";
    s.push(1);
    visited.clear();
    dfs_iterative(graph, s, visited);
    return 0;
}
