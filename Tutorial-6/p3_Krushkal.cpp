#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int u,v,w;

    Edge(){};
    Edge(int a,int b,int c):u(a),v(b),w(c){}
};

class DSU {
    public:

    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;  // each node is its own parent initially
    }

    int findParent(int x) {
        if (parent[x] != x)
            parent[x] = findParent(parent[x]); // Optimized
        return parent[x];
    }

    void Union(int x, int y) {
        x = findParent(x);
        y = findParent(y);
        if (x != y) {
            if (rank[x] < rank[y])
                parent[x] = y;
            else if (rank[x] > rank[y])
                parent[y] = x;
            else {
                parent[y] = x;
                rank[x]++;
            }
        }
    }
};

bool compare(Edge a,Edge b){
    return a.w<b.w;
}

int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges accordingly:"<<endl;
    cin>>V>>E;

    vector<Edge> edges(E);
    cout<<"Enter edges with weight:"<<endl;
    for(int i=0;i<E;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }

    sort(edges.begin(),edges.end(),compare);

    DSU dsu(V);
    vector<Edge> mst;
    int totalWeight=0;

    for(int i=0;i<E;i++){

        if(dsu.findParent(edges[i].u)!=dsu.findParent(edges[i].v)){
            mst.push_back(edges[i]);
            totalWeight+=edges[i].w;
            dsu.Union(edges[i].u,edges[i].v);
        }
    }

    cout<<"MST from Kruskal's algorithem:-"<<endl;
    for(Edge e:mst){
        cout<<e.u<<" -> "<<e.v<<" : "<<e.w<<endl;
    }
    cout<<"Total weight:"<<totalWeight<<endl;
    return 0;
}
