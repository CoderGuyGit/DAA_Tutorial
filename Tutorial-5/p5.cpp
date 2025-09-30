#include<bits/stdc++.h>
using namespace std;

void Display(vector<int> cut,int len){
    if(len==0)return;
    if(cut[len]==0){
        cout<<len;
        return;
    }
    
    cout<<cut[len]<<" ";
    Display(cut,len-cut[len]);
}

int main(){
    int n;
    cout<<"Enter rod size:";
    cin>>n;
    
    //Assum indexing from 1 to n;
    vector<int> price(n+1,0);
    cout<<"Enter price per length:"<<endl;
    for(int i=1;i<=n;i++)cin>>price[i];

    vector<int> cut(n+1,0);
    vector<int> profit(n+1,0);
    for(int i=1;i<=n;i++)profit[i]=price[i];

    for(int len=1;len<=n;len++){
        for(int r=0;r<=len;r++){
            int temp=price[r]+profit[len-r];
            if(temp>profit[len]){
                profit[len]=temp;
                cut[len]=r;
            }
        }
    }

    cout<<"Max profit for cutting rod:"<<profit[n]<<endl;
    cout<<"Cuts to make:"<<endl;
    Display(cut,n);
    return 0;
}