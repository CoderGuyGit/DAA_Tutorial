#include<bits/stdc++.h>
using namespace std;

void bellmanFord(int V,int E,vector<tuple<int,int,int>>& edges,int src){
    vector<int> dist(V,INT_MAX);
    dist[src]=0;

    for(int i=1;i<=V-1;i++){
        for(int j=0;j<E;j++){
            int u,v,w;
            tie(u,v,w)=edges[j];
            if(dist[u]!=INT_MAX&&dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }

    bool negCycle=false;
    for(int j=0;j<E;j++){
        int u,v,w;
        tie(u,v,w)=edges[j];
        if(dist[u]!=INT_MAX&&dist[u]+w<dist[v]){
            negCycle=true;
            break;
        }
    }

    if(negCycle){
        cout<<"\nNegative weight cycle detected and reachable from source!"<<endl;
        return;
    }

    cout<<"\nVertex\tDistance from Source"<<endl;
    for(int i=0;i<V;i++){
        if(dist[i]==INT_MAX)cout<<i<<"\tINF"<<endl;
        else cout<<i<<"\t"<<dist[i]<<endl;
    }
}

int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges accordingly:"<<endl;
    cin>>V>>E;
    
    cout<<"Vertices are labeled from 0 to n-1."<<endl;
    cout<<"Enter all the edges in "<<E<<" lines with corresponding weights:"<<endl;

    vector<tuple<int,int,int>> edges;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(make_tuple(u,v,w));
    }

    int src;
    cout<<"\nEnter source vertex: ";
    cin>>src;

    bellmanFord(V,E,edges,src);
    return 0;
}
