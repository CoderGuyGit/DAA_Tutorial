#include<bits/stdc++.h>
using namespace std;

void printTree(vector<vector<int>> root,int i,int j){
    if(i>j){
        cout<<"(NULL)";
        return;
    }
    if(i==j){
        cout<<'('<<i<<')';
        return;
    }
    cout<<'(';
    printTree(root,i,root[i][j]-1);
    cout<<" <- "<<root[i][j]<<" -> ";
    printTree(root,root[i][j]+1,j);
    cout<<')';
}

int main(){
    int n;
    cout<<"Enter the number of keys:";
    cin>>n;

    vector<float>p(n,0);
    cout<<"Enter their probabillities:";
    for(int i=0;i<n;i++)cin>>p[i];

    //Assuming key index range 0 to n-1;
    vector<vector<float>> e(n,vector<float>(n,0));
    vector<vector<int>> root(n,vector<int>(n,0));
    vector<vector<float>> w(n,vector<float>(n,0));

    for(int i=0;i<n;i++){
        w[i][i]=p[i];
        root[i][i]=i;
        e[i][i]=p[i];
    }

    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            e[i][j]=FLT_MAX;
            w[i][j]=w[i][j-1]+p[j];
            for(int r=i;r<=j;r++){
                float temp=0;
                if(r>i)temp+=e[i][r-1];
                if(r<j)temp+=e[r+1][j];
                temp+=w[i][j];
                if(temp<e[i][j]){
                    e[i][j]=temp;
                    root[i][j]=r;
                }
            }
        }
    }
    cout<<"Expected cost:"<<e[0][n-1]<<endl;

    printTree(root,0,n-1);
    return 0;
}