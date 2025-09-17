#include<iostream>
#include<vector>

using namespace std;

long matrixChainMultiplyCost(int i,int j,vector<int>p){
    if(i==j)return 0;
    long minCost=-1;
    long cost=0;
    for(int k=i;k<j;k++){
        cost=matrixChainMultiplyCost(i,k,p)+matrixChainMultiplyCost(k+1,j,p)+p[i-1]*p[k]*p[j];
        
        if( minCost>cost || minCost==-1)minCost=cost;
    }
    return minCost;
}

int main(){
    int n;
    cout<<"Enter the number of matrices:";
    cin>>n;

    vector<int> p(n+1,0);
    cout<<"Enter the dimensions in sequence"<<endl;
    
    for(int i=0;i<n+1;i++)cin>>p[i];

    long cost=matrixChainMultiplyCost(1,n,p);
    cout<<"Minimum number of multiplications:"<<cost<<endl;
    

    return 0;
}