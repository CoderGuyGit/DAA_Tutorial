#include<bits/stdc++.h>
using namespace std;

bool DFS_Visit(int v,vector<vector<int>>& adj,vector<int>& parent,vector<bool>& visited){
    visited[v]=true;
    bool hasCycle=false;

    for(int i=0;i<adj.size() && !hasCycle;i++){
        if(adj[v][i]){
            if(!visited[i]){
                parent[i]=v;
                hasCycle=DFS_Visit(i,adj,parent,visited);
            }
            else if(i != parent[v])return true;
        }
    }
    return hasCycle;
}

bool DFS_Cycle_Detect(int V,vector<vector<int>> adj){
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);

    bool hasCycle=false;

    for(int i=0;i<V && !hasCycle;i++){
        if(!visited[i]){
            hasCycle=DFS_Visit(i,adj,parent,visited);
        }
    }
    return hasCycle;
}

int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges accordingly:"<<endl;
    cin>>V>>E;

    cout<<"Vertices are labeled from 0 to n-1."<<endl;
    cout<<"Enter the All the edges in "<<E<<" lines:"<<endl;

    vector<vector<int>> adj(V,vector<int>(V,0));

    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        adj[x][y]=adj[y][x]=1;
    }

    if(DFS_Cycle_Detect(V,adj))cout<<"This graph has cycles!";
    else cout<<"No cycles detected";

    cout<<endl;
    return 0;
}