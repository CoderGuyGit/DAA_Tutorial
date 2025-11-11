#include<bits/stdc++.h>
using namespace std;

bool hamiltonian(int u,vector<int>& path,vector<vector<int>>& adj,vector<bool>& visited,int V){
    if(path.size()==V){
        for(int v:adj[u]){
            if(v==1){
                path.push_back(1);
                return true;
            }
        }
        return false;
    }

    for(int v:adj[u]){
        if(!visited[v]){
            visited[v]=true;
            path.push_back(v);
            if(hamiltonian(v,path,adj,visited,V))return true;
            visited[v]=false;
            path.pop_back();
        }
    }
    return false;
}

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>V>>E;

    vector<vector<int>> adj(V+1);
    cout<<"Enter edges in format u v:"<<endl;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> path;
    vector<bool> visited(V+1,false);
    path.push_back(1);
    visited[1]=true;

    if(hamiltonian(1,path,adj,visited,V)){
        cout<<"Hamiltonian Cycle: ";
        for(int x:path)cout<<x<<" ";
        cout<<endl;
    }else cout<<"none"<<endl;

    return 0;
}
