#include <bits/stdc++.h>
using namespace std;

// Placeholder function — you will implement it
bool hasCycleDirected(map<int, vector<int>>& graph) {
    return false;
}

bool hasCycleUndirected(map<int, vector<int>>& graph) {
    return false;
}

void printGraph(const map<int, vector<int>>& graph) {
    for (auto &p : graph) {
        cout << p.first << " -> ";
        for (int v : p.second) cout << v << " ";
        cout << endl;
    }
}

int main() {
    // Directed Graph (cycle between 1 -> 2 -> 3 -> 1)
    map<int, vector<int>> directedGraph = {
        {1, {2}},
        {2, {3}},
        {3, {1}},   // cycle here
        {4, {5}},
        {5, {}}
    };

    // Undirected Graph (cycle between 1 - 2 - 3 - 1)
    map<int, vector<int>> undirectedGraph = {
        {1, {2, 3}},
        {2, {1, 3}},
        {3, {1, 2}},
        {4, {5}},
        {5, {4}}
    };

    cout << "Directed Graph:" << endl;
    printGraph(directedGraph);
    if (hasCycleDirected(directedGraph)) 
        cout << "Cycle Detected (Directed)" << endl;
    else 
        cout << "No Cycle (Directed)" << endl;

    cout << "\nUndirected Graph:" << endl;
    printGraph(undirectedGraph);
    if (hasCycleUndirected(undirectedGraph)) 
        cout << "Cycle Detected (Undirected)" << endl;
    else 
        cout << "No Cycle (Undirected)" << endl;

    return 0;
}
