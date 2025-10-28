#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v,w;
    Edge(int vertex, int weight):v(vertex),w(weight){}
};

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>V>>E;

    vector<vector<Edge>> adj(V);

    cout<<"Enter edges with weight (u v w):"<<endl;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(Edge(v,w));
        adj[v].push_back(Edge(u,w)); // undirected graph
    }

    vector<int> key(V,INT_MAX);   // smallest edge to connect each vertex
    vector<int> parent(V,-1);     // MST
    vector<bool> inMST(V,false);  // Visited Space

    // Min-heap of (weight, vertex)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    key[0]=0;
    pq.push({0,0});

    while (!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        if(inMST[u])continue;
        inMST[u]=true;

        for(auto edge:adj[u]){
            int v=edge.v;
            int w=edge.w;

            if(!inMST[v] && w<key[v]){
                key[v]=w;
                pq.push({key[v],v});
                parent[v]=u;
            }
        }
    }

    cout<<endl<<"MST from Prim's algorithm:"<<endl;
    int totalWeight=0;

    for(int i=1;i<V;i++){
        cout<<parent[i]<<" -> "<<i<<" : "<<key[i]<<endl;
        totalWeight+= key[i];
    }
    cout<<"Total weight: "<<totalWeight<<endl;

    return 0;
}
