#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> M){
    cout<<endl;
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M[i].size();j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

enum COLOR {White,Grey,Black};

void BFS(int V,vector<vector<int>> adj){
    queue<int> q;
    vector<COLOR> color(V,White);

    for(int i=0;i<V;i++){
        if(color[i]==White){
            q.push(i);
        
            while(!q.empty()){
                int v=q.front();
                q.pop();
                color[v]=Grey;
                cout<<v<<" ";
                for(int j=0;j<V;j++){
                    if(adj[v][j] && color[j]==White){
                        q.push(j);
                        color[j]=Grey;
                    }
                }
                color[v]=Black;
            }
        }
    }
    cout<<endl;
}

void DFS_Visit(int v,vector<vector<int>>& adj,vector<int>& parent,vector<bool>& visited,vector<int>& d,vector<int>& f,int& time){
    //There is a small v meaning vertice

    visited[v]=true;
    d[v]=++time;
    cout<<v<<" ";

    for(int i=0;i<adj.size();i++){
        if(adj[v][i] && !visited[i]){
            parent[i]=v;
            DFS_Visit(i,adj,parent,visited,d,f,time);
        }
    }
    f[v]=++time;
}

void DFS(int V,vector<vector<int>> adj){
    vector<int> d(V,-1);    //Discovery time , -1 means not discovered
    vector<int> f(V,-1);    //Finish time -1 means not finished

    vector<bool> visited(V,false);
    int time=0;

    vector<int> parent(V,-1);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS_Visit(i,adj,parent,visited,d,f,time);
        }
    }

    cout<<"Edge classifications:-"<<endl;
    //Only for Directed Graphs!
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]){
                cout<<i<<" -> "<<j<<" : ";
                if(parent[j]==i){
                    cout<<"Tree edge";
                }
                else if(d[i]>d[j] && f[i]<f[j]){
                    cout<<"Back Edge";
                }
                else if(d[i]<d[j] && f[i]>f[j]){
                    cout<<"Forward Edge";    
                }
                else if(f[i]<d[j] || d[i]>f[j]){
                    cout<<"Cross Edge";
                }
                else cout<<"Invalid";
                
                cout<<endl;
            }
        }
    }

    cout<<endl;
        
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

    cout<<endl;
    cout<<"BFS Traversal:";
    BFS(V,adj);
    
    cout<<endl;
    cout<<"DFS Traversal:";
    DFS(V,adj);

    display(adj);
    return 0;
}