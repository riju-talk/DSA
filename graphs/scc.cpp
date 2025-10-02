#include <bits/stdc++.h>
using namespace std;

int scc(map<int, vector<int>>& graph){
    queue<int> q;
    set<int> visited;
    int temp = graph.begin()->first;
    q.push(temp);
    
}


int main() {
map<int, vector<int>> graph = {
    {1, {2, 3}},
    {2, {1, 4}},
    {3, {1, 4, 5}},
    {4, {2, 3, 5}},
    {5, {3, 4, 6}},
    {6, {5}},
    {7, {8}},  // Separate isolated component
    {8, {7}}
};    // Print the adjacency list
    for (auto &p : graph) {
        cout << p.first << " -> ";
        for (int v : p.second) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
