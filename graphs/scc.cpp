#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kosaraju(map<int, vector<int>>& graph){
    set<int> visited;
    vector<int> order;

    function<void(int)> dfs1 = [&](int u){
        visited.insert(u);
        for (int v : graph[u]) {
            if (!visited.count(v)) dfs1(v);
        }
        order.push_back(u);
    };

    for (auto &p : graph) {
        if (!visited.count(p.first)) dfs1(p.first);
    }

    map<int, vector<int>> rev;
    for (auto &p : graph) rev[p.first];
    for (auto &p : graph) {
        for (int v : p.second) {
            rev[v].push_back(p.first);
        }
    }

    visited.clear();
    vector<vector<int>> sccs;
    function<void(int, vector<int>&)> dfs2 = [&](int u, vector<int> &comp){
        visited.insert(u);
        comp.push_back(u);
        for (int v : rev[u]) {
            if (!visited.count(v)) dfs2(v, comp);
        }
    };

    for (auto it = order.rbegin(); it != order.rend(); ++it) {
        if (!visited.count(*it)) {
            vector<int> comp;
            dfs2(*it, comp);
            sccs.push_back(comp);
        }
    }
    return sccs;
}

vector<vector<int>> tarjan(map<int, vector<int>>& graph){
    unordered_map<int,int> disc, low;
    unordered_map<int,bool> onStack;
    stack<int> st;
    int time = 0;
    vector<vector<int>> sccs;

    for (auto &p : graph) {
        disc[p.first] = 0;
        low[p.first] = 0;
        onStack[p.first] = false;
    }

    function<void(int)> dfs = [&](int u){
        disc[u] = low[u] = ++time;
        st.push(u);
        onStack[u] = true;

        for (int v : graph[u]) {
            if (disc[v] == 0) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (onStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u]) {
            vector<int> comp;
            while (true) {
                int w = st.top(); st.pop();
                onStack[w] = false;
                comp.push_back(w);
                if (w == u) break;
            }
            sccs.push_back(comp);
        }
    };

    for (auto &p : graph) {
        if (disc[p.first] == 0) dfs(p.first);
    }
    return sccs;
}

int main() {
    map<int, vector<int>> graph = {
        {1, {2}},
        {2, {3}},
        {3, {1}},
        {4, {5}},
        {5, {6}},
        {6, {4}},
        {7, {8}},
        {8, {7}},
        {9, {10}},
        {10, {}}
    };

    auto ks = kosaraju(graph);
    cout << "Kosaraju:\n";
    for (auto &comp : ks) {
        for (int x : comp) cout << x << " ";
        cout << "\n";
    }

    auto ts = tarjan(graph);
    cout << "Tarjan:\n";
    for (auto &comp : ts) {
        for (int x : comp) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
