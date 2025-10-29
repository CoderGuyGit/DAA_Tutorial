#include<bits/stdc++.h>
using namespace std;

void dfs_visit(int u,vector<vector<int>>& adj,vector<bool>& visited,stack<int>& nodes){
    visited[u]=true;

    for(int v:adj[u]){
        if(!visited[v])dfs_visit(v,adj,visited,nodes);
    }
    nodes.push(u);
}


int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges accordingly:"<<endl;
    cin>>V>>E;
    
    
    cout<<"Vertices are labeled from 0 to n-1."<<endl;
    cout<<"Enter the All the edges in "<<E<<" lines:"<<endl;
    
    vector<vector<int>> adj(V);

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    stack<int> nodes;

    vector<bool> visited(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i])dfs_visit(i,adj,visited,nodes);
    }

    while(!nodes.empty()){
        cout<<nodes.top()<<" -> ";
        nodes.pop();
    }

    cout<<"NULL"<<endl;
    return 0;
}