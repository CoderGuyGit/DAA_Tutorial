#include<bits/stdc++.h>
using namespace std;

void floydWarshall(int V,vector<vector<int>>& dist){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX&&dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    bool negCycle=false;
    for(int i=0;i<V;i++){
        if(dist[i][i]<0){
            negCycle=true;
            break;
        }
    }

    if(negCycle){
        cout<<"\nNegative weight cycle detected!"<<endl;
        return;
    }

    cout<<"\nAll-Pairs Shortest Distances:"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INT_MAX)cout<<"INF\t";
            else cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges accordingly:"<<endl;
    cin>>V>>E;
    
    cout<<"Vertices are labeled from 0 to n-1."<<endl;
    cout<<"Enter all the edges in "<<E<<" lines with corresponding weights:"<<endl;

    vector<vector<int>> dist(V,vector<int>(V,INT_MAX));

    for(int i=0;i<V;i++)dist[i][i]=0;

    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
        // For undirected graph:
        // dist[v][u]=w;
    }

    floydWarshall(V,dist);
    return 0;
}
