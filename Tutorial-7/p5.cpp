#include<bits/stdc++.h>
using namespace std;

struct Item{
    int profit,weight;
    double ratio;
};

struct Node{
    int level,profit,weight;
    double bound;
    vector<int> taken;
};

bool cmp(Item a,Item b){return a.ratio>b.ratio;}

double bound(Node u,int n,int C,vector<Item>& items){
    if(u.weight>=C)return 0;
    double profit_bound=u.profit;
    int j=u.level+1;
    int totweight=u.weight;
    while(j<n && totweight+items[j].weight<=C){
        totweight+=items[j].weight;
        profit_bound+=items[j].profit;
        j++;
    }
    if(j<n)profit_bound+=(C-totweight)*items[j].ratio;
    return profit_bound;
}

struct Compare{
    bool operator()(Node a,Node b){return a.bound<b.bound;}
};

int main(){
    int n,C;
    cout<<"Enter number of items and capacity:"<<endl;
    cin>>n>>C;
    vector<Item> items(n);
    cout<<"Enter profit and weight of each item:"<<endl;
    for(int i=0;i<n;i++){
        cin>>items[i].profit>>items[i].weight;
        items[i].ratio=(double)items[i].profit/items[i].weight;
    }

    sort(items.begin(),items.end(),cmp);

    priority_queue<Node,vector<Node>,Compare> pq;
    Node u,v;
    u.level=-1; u.profit=0; u.weight=0; u.taken=vector<int>(n,0);
    u.bound=bound(u,n,C,items);
    pq.push(u);

    int maxProfit=0;
    vector<int> bestSet(n,0);
    int expanded=0,pruned=0;

    while(!pq.empty()){
        u=pq.top(); pq.pop();
        expanded++;
        if(u.bound<=maxProfit){
            pruned++;
            continue;
        }
        if(u.level==n-1)continue;

        // take next item
        v.level=u.level+1;
        v.weight=u.weight+items[v.level].weight;
        v.profit=u.profit+items[v.level].profit;
        v.taken=u.taken;
        v.taken[v.level]=1;
        if(v.weight<=C && v.profit>maxProfit){
            maxProfit=v.profit;
            bestSet=v.taken;
        }
        v.bound=bound(v,n,C,items);
        if(v.bound>maxProfit)pq.push(v);
        else pruned++;

        // don't take next item
        v.weight=u.weight;
        v.profit=u.profit;
        v.taken=u.taken;
        v.taken[v.level]=0;
        v.bound=bound(v,n,C,items);
        if(v.bound>maxProfit)pq.push(v);
        else pruned++;
    }

    cout<<"Optimal profit: "<<maxProfit<<endl;
    cout<<"Items taken (0/1): ";
    for(int i=0;i<n;i++)cout<<bestSet[i]<<" ";
    cout<<endl;
    cout<<"Nodes expanded: "<<expanded<<endl;
    cout<<"Nodes pruned: "<<pruned<<endl;

    return 0;
}
