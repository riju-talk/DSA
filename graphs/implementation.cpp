#include <bits/stdc++.h>
using namespace std;

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

    return 0;
}
