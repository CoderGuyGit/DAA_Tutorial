#include<bits/stdc++.h>
using namespace std;

bool bfs(int s,int t,vector<vector<int>>& cap,vector<int>& par){
    int n=cap.size();
    fill(par.begin(),par.end(),-1);
    par[s]=-2;
    queue<pair<int,int>> q;
    q.push({s,INT_MAX});

    while(!q.empty()){
        int u=q.front().first; q.pop();
        for(int v=0;v<n;v++){
            if(par[v]==-1 && cap[u][v]>0){
                par[v]=u;
                if(v==t)return true;
                q.push({v,1});
            }
        }
    }
    return false;
}

int main(){
    int n1,n2,m;
    cout<<"Enter number of vertices in left and right sets: ";
    cin>>n1>>n2;
    cout<<"Enter number of edges: ";
    cin>>m;

    int S=0;
    int T=n1+n2+1;
    int V=T+1;
    vector<vector<int>> cap(V,vector<int>(V,0));

    cout<<"Enter edges (u v) where u in [1,"<<n1<<"], v in [1,"<<n2<<"]:"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        v+=n1;            
        cap[u][v]=1;
    }

    for(int u=1;u<=n1;u++)cap[S][u]=1;         
    for(int v=n1+1;v<=n1+n2;v++)cap[v][T]=1;    

    vector<int> par(V);
    int flow=0;

    while(bfs(S,T,cap,par)){
      
        int bottleneck=1;

     
        for(int v=T;v!=S;v=par[v]){
            int u=par[v];
            cap[u][v]-=bottleneck;
            cap[v][u]+=bottleneck;
        }
        flow+=bottleneck;
    }

    cout<<"\nMaximum Matching Size: "<<flow<<"\n";
    cout<<"Matched pairs (u,v):\n";
    for(int u=1;u<=n1;u++){
        for(int v=n1+1;v<=n1+n2;v++){
            if(cap[v][u]>0)cout<<"("<<u<<","<<(v-n1)<<")\n";
        }
    }

    return 0;
}
