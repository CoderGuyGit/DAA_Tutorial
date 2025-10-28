#include<bits/stdc++.h>
using namespace std;

enum Color {White,Grey,Black};

bool DFS_Visit(int v,vector<vector<int>>& adj,vector<Color>& color){
    color[v]=Grey;
    bool hasCycle=false;

    for(int i=0;i<adj.size() && !hasCycle;i++){
        if(adj[v][i]){
            if(color[i]==Grey)return true;
            else if(color[i]==White)hasCycle=DFS_Visit(i,adj,color);
        }
    }
    color[v]=Black;
    return hasCycle;
}

bool DFS_Cycle_Detect(int V,vector<vector<int>> adj){
    vector<Color> color(V,White);
    bool hasCycle=false;

    for(int i=0;i<V && !hasCycle;i++){
        if(color[i]==White){
            hasCycle=DFS_Visit(i,adj,color);
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
        adj[x][y]=1;
    }

    if(DFS_Cycle_Detect(V,adj))cout<<"This graph has cycles!";
    else cout<<"No cycles detected";

    cout<<endl;
    return 0;
}