#include<bits/stdc++.h>
using namespace std;

void dijkstra(int V,vector<vector<pair<int,int>>>& adj,int src,int tgt){
    vector<int> dist(V,INT_MAX);
    vector<int> parent(V,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    dist[src]=0;
    pq.push(make_pair(0,src));

    while(!pq.empty()){
        pair<int,int> p=pq.top();
        pq.pop();
        int d=p.first;
        int u=p.second;
        if(d>dist[u])continue;

        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            int w=adj[u][i].second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
                pq.push(make_pair(dist[v],v));
            }
        }
    }

    if(dist[tgt]==INT_MAX){
        cout<<"\nNo path exists from "<<src<<" to "<<tgt<<endl;
        return;
    }

    cout<<"\nShortest distance from "<<src<<" to "<<tgt<<" is: "<<dist[tgt]<<endl;

    vector<int> path;
    for(int v=tgt;v!=-1;v=parent[v])path.push_back(v);
    reverse(path.begin(),path.end());

    cout<<"Shortest path: ";
    for(int i=0;i<path.size();i++)cout<<path[i]<<" ";
    cout<<endl;
}

int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges accordingly:"<<endl;
    cin>>V>>E;
    
    cout<<"Vertices are labeled from 0 to "<<V-1<<"."<<endl;
    cout<<"Enter all the edges in "<<E<<" lines with corresponding weights (u v w):"<<endl;

    vector<vector<pair<int,int>>>adj(V);

    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        // For undirected graph:
        // adj[v].push_back(make_pair(u,w));
    }

    int src,tgt;
    cout<<"\nEnter source vertex: ";
    cin>>src;
    cout<<"Enter target vertex: ";
    cin>>tgt;

    dijkstra(V,adj,src,tgt);
    return 0;
}
