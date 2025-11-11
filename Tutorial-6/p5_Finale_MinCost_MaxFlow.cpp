#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int v,cap,cost,rev;
};

void addEdge(vector<vector<Edge>>& g,int u,int v,int cap,int cost){
    g[u].push_back({v,cap,cost,(int)g[v].size()});
    g[v].push_back({u,0,-cost,(int)g[u].size()-1});
}

pair<int,int> minCostMaxFlow(vector<vector<Edge>>& g,int s,int t){
    int n=g.size();
    int flow=0,cost=0;
    vector<int> dist(n),parv(n),pare(n),pot(n,0);

    while(true){
        fill(dist.begin(),dist.end(),INT_MAX);
        dist[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});

        while(!pq.empty()){
            pair<int,int> cur=pq.top();pq.pop();
            int d=cur.first,u=cur.second;
            if(d>dist[u])continue;
            for(int i=0;i<g[u].size();i++){
                Edge &e=g[u][i];
                if(e.cap>0 && dist[e.v]>d+e.cost+pot[u]-pot[e.v]){
                    dist[e.v]=d+e.cost+pot[u]-pot[e.v];
                    parv[e.v]=u;
                    pare[e.v]=i;
                    pq.push({dist[e.v],e.v});
                }
            }
        }

        if(dist[t]==INT_MAX)break;

        for(int i=0;i<n;i++)if(dist[i]<INT_MAX)pot[i]+=dist[i];

        int addFlow=INT_MAX;
        for(int v=t;v!=s;v=parv[v])
            addFlow=min(addFlow,g[parv[v]][pare[v]].cap);

        for(int v=t;v!=s;v=parv[v]){
            Edge &e=g[parv[v]][pare[v]];
            e.cap-=addFlow;
            g[e.v][e.rev].cap+=addFlow;
            cost+=addFlow*e.cost;
        }
        flow+=addFlow;
    }

    return make_pair(flow,cost);
}

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges:"<<endl;
    cin>>V>>E;

    vector<vector<Edge>> g(V);
    cout<<"Enter edges (u v capacity cost):"<<endl;
    for(int i=0;i<E;i++){
        int u,v,cap,cost;
        cin>>u>>v>>cap>>cost;
        addEdge(g,u,v,cap,cost);
    }

    int s,t;
    cout<<"Enter source and sink:"<<endl;
    cin>>s>>t;

    pair<int,int> res=minCostMaxFlow(g,s,t);
    int flow=res.first;
    int minCost=res.second;

    cout<<"\nMaximum Flow:"<<flow<<endl;
    cout<<"Minimum Cost:"<<minCost<<endl;

    return 0;
}
