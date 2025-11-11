#include <bits/stdc++.h>
using namespace std;

bool bfs(int s, int t, vector<vector<int>>& cap, vector<int>& parent) {
    int n = cap.size();
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int,int>> q;
    q.push({s, INT_MAX});

    while(!q.empty()) {
        int u = q.front().first, flow = q.front().second;
        q.pop();

        for(int v=0;v<n;v++) {
            if(parent[v]==-1 && cap[u][v] > 0) {
                parent[v] = u;
                int new_flow = min(flow, cap[u][v]);
                if(v == t) return true;
                q.push({v, new_flow});
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> cap(V, vector<int>(V, 0));

    cout << "Enter edges (u v capacity):\n";
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cap[u][v] = w;
    }

    int s, t;
    cout << "Enter source and sink: ";
    cin >> s >> t;

    int maxFlow = 0;
    vector<int> parent(V);

    cout << "\n--- Augmenting Paths ---\n";
    while(bfs(s, t, cap, parent)) {
        // Find bottleneck
        int bottleneck = INT_MAX;
        for(int v = t; v != s; v = parent[v])
            bottleneck = min(bottleneck, cap[parent[v]][v]);

        // Show augmenting path
        vector<int> path;
        for(int v = t; v != s; v = parent[v]) path.push_back(v);
        path.push_back(s);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for(int x : path) cout << x << " ";
        cout << " | Bottleneck: " << bottleneck << "\n";

        // Update residual capacities
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            cap[u][v] -= bottleneck;
            cap[v][u] += bottleneck;
        }

        maxFlow += bottleneck;
    }

    cout << "\nMaximum Flow Value: " << maxFlow << "\n";

    // Print residual network
    cout << "\n--- Final Residual Network ---\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++)
            if(cap[i][j] > 0)
                cout << i << " -> " << j << " | residual: " << cap[i][j] << "\n";
    }

    // Find Min-Cut
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v = 0; v < V; v++) {
            if(cap[u][v] > 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << "\n--- Minimum Cut ---\n";
    int cutCap = 0;
    for(int u = 0; u < V; u++)
        if(visited[u])
            for(int v = 0; v < V; v++)
                if(!visited[v] && cap[u][v] == 0) 
                    cutCap += cap[v][u];
    cout << "Cut capacity: " << cutCap << "\n";
}
