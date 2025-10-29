#include<bits/stdc++.h>
using namespace std;

void dfs_visit(int u,vector<vector<int>>& adj,vector<bool>& visited,stack<int>& finished){
    visited[u]=true;

    for(int v:adj[u]){
        if(!visited[v])dfs_visit(v,adj,visited,finished);
    }
    finished.push(u);
}

void dfs_visit(int u,vector<vector<int>>& adj,vector<bool>& visited){
    visited[u]=true;

    for(int v:adj[u]){
        if(!visited[v])dfs_visit(v,adj,visited);
    }
    cout<<u<<" ";
}

int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges accordingly:"<<endl;
    cin>>V>>E;
    
    
    cout<<"Vertices are labeled from 0 to n-1."<<endl;
    cout<<"Enter the All the edges in "<<E<<" lines:"<<endl;
    
    vector<vector<int>> adj(V);
    vector<vector<int>> adjT(V);    //Inverted Graph

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    
    stack<int> finished;

    vector<bool> visited(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i])dfs_visit(i,adj,visited,finished);
    }

    visited=vector<bool>(V,false);
    int component=1;

    while(!finished.empty()){
        int u=finished.top();
        finished.pop();

        if(!visited[u]){
            cout<<"Component "<<component<<" :-"<<endl;
            dfs_visit(u,adjT,visited);
            cout<<endl;
            component++;
        }
    }

    return 0;
}