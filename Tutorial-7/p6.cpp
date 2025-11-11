#include<bits/stdc++.h>
using namespace std;

struct Node{
    vector<int> path;
    double cost;
    vector<vector<int>> reducedMatrix;
    int vertex;
    int level;
};

struct Compare{
    bool operator()(Node a,Node b){return a.cost>b.cost;}
};

int reduceMatrix(vector<vector<int>>& mat,int n){
    int reduction=0;
    for(int i=0;i<n;i++){
        int rowMin=INT_MAX;
        for(int j=0;j<n;j++)if(mat[i][j]!=INT_MAX)rowMin=min(rowMin,mat[i][j]);
        if(rowMin!=INT_MAX && rowMin>0){
            for(int j=0;j<n;j++)if(mat[i][j]!=INT_MAX)mat[i][j]-=rowMin;
            reduction+=rowMin;
        }
    }
    for(int j=0;j<n;j++){
        int colMin=INT_MAX;
        for(int i=0;i<n;i++)if(mat[i][j]!=INT_MAX)colMin=min(colMin,mat[i][j]);
        if(colMin!=INT_MAX && colMin>0){
            for(int i=0;i<n;i++)if(mat[i][j]!=INT_MAX)mat[i][j]-=colMin;
            reduction+=colMin;
        }
    }
    return reduction;
}

int main(){
    int n;
    cout<<"Enter number of cities:"<<endl;
    cin>>n;
    vector<vector<int>> cost(n,vector<int>(n));
    cout<<"Enter cost matrix (row-wise):"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
            if(i==j)cost[i][j]=INT_MAX;
        }
    }

    priority_queue<Node,vector<Node>,Compare> pq;
    vector<vector<int>> initialMatrix=cost;
    int initialCost=reduceMatrix(initialMatrix,n);

    Node root;
    root.path={0};
    root.vertex=0;
    root.level=0;
    root.reducedMatrix=initialMatrix;
    root.cost=initialCost;

    pq.push(root);

    int minCost=INT_MAX;
    vector<int> bestPath;
    int expanded=0;

    while(!pq.empty()){
        Node curr=pq.top(); pq.pop();
        expanded++;

        if(curr.level==n-1){
            int last=curr.vertex;
            int finalCost=(curr.cost==INT_MAX?0:curr.cost)+cost[last][0];
            if(finalCost<minCost){
                minCost=finalCost;
                bestPath=curr.path;
                bestPath.push_back(0);
            }
            continue;
        }

        for(int i=0;i<n;i++){
            if(find(curr.path.begin(),curr.path.end(),i)==curr.path.end()){
                Node child;
                child.level=curr.level+1;
                child.path=curr.path;
                child.path.push_back(i);
                child.vertex=i;
                child.reducedMatrix=curr.reducedMatrix;

                for(int j=0;j<n;j++){
                    child.reducedMatrix[curr.vertex][j]=INT_MAX;
                    child.reducedMatrix[j][i]=INT_MAX;
                }
                child.reducedMatrix[i][0]=INT_MAX;

                int costAdded=(curr.reducedMatrix[curr.vertex][i]==INT_MAX?0:curr.reducedMatrix[curr.vertex][i]);
                child.cost=curr.cost+costAdded+reduceMatrix(child.reducedMatrix,n);

                if(child.cost<minCost)pq.push(child);
            }
        }
    }

    cout<<"Optimal tour: ";
    for(int x:bestPath)cout<<char('A'+x)<<" ";
    cout<<"\nTotal cost: "<<minCost<<endl;
    cout<<"Nodes expanded: "<<expanded<<endl;

    return 0;
}
