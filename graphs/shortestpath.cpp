#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, vector<int>> graph_unweighted = {
    {1, {2, 3}},
    {2, {1, 4, 5}},
    {3, {1, 6}},
    {4, {2}},
    {5, {2, 6}},
    {6, {3, 5, 7}},
    {7, {6}}
};
    // Print the adjacency list
    for (auto &p : graph_unweighted) {
        cout << p.first << " -> ";
        for (int v : p.second) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
