#include<bits/stdc++.h>
using namespace std;

void subsetSum(vector<int>& S,int i,vector<int>& subset,int sum,int target){
    if(sum==target){
        cout<<"{ ";
        for(int x:subset)cout<<x<<" ";
        cout<<"}"<<endl;
        return;
    }

    if(i==S.size() || sum>S[i])return;

    int remaining=0;
    for(int j=i;j<S.size();j++)remaining+=S[j];
    if(sum+remaining<target)return; 

    subset.push_back(S[i]);
    subsetSum(S,i+1,subset,sum+S[i],target);
    subset.pop_back();

    subsetSum(S,i+1,subset,sum,target);
}

int main(){
    int n,T;
    cout<<"Enter number of elements in the set:"<<endl;
    cin>>n;
    vector<int> S(n);
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++)cin>>S[i];

    cout<<"Enter target sum:"<<endl;
    cin>>T;

    vector<int> subset;
    cout<<"Subsets that sum to "<<T<<":"<<endl;
    subsetSum(S,0,subset,0,T);

    return 0;
}
