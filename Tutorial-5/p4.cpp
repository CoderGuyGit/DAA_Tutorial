#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,n;
    cout<<"Enter the Eggcount:";
    cin>>k;
    
    cout<<"How many floors:";
    cin>>n;

    vector<vector<int>> egg_drop(n+1,vector<int>(k+1,INT_MAX));

    for(int i=0;i<=n;i++){
        egg_drop[i][0]=0;
        egg_drop[i][1]=i;
    }
    for(int i=0;i<=k;i++){
        egg_drop[0][i]=0;
        egg_drop[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            for(int r=1;r<=i;r++){
                int temp=max(egg_drop[r-1][j-1],egg_drop[i-r][j])+1;
                if(egg_drop[i][j]>temp)egg_drop[i][j]=temp;
            }
        }
    }

    cout<<"Minimum moves to be made:"<<egg_drop[n][k]<<endl;

    return 0;
}