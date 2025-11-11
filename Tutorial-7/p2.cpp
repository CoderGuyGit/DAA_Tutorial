#include<bits/stdc++.h>
using namespace std;

int mindiff=INT_MAX;
vector<int> bestA,bestB;

void solve(vector<int>& arr,int i,vector<int>& A,vector<int>& B,int sumA,int sumB){
    if(i==arr.size()){
        int diff=abs(sumA-sumB);
        if(diff<mindiff){
            mindiff=diff;
            bestA=A;
            bestB=B;
        }
        return;
    }

    A.push_back(arr[i]);
    solve(arr,i+1,A,B,sumA+arr[i],sumB);
    A.pop_back();

    B.push_back(arr[i]);
    solve(arr,i+1,A,B,sumA,sumB+arr[i]);
    B.pop_back();
}

int main(){
    int n;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int> A,B;
    solve(arr,0,A,B,0,0);

    cout<<"Subset 1: ";
    for(int x:bestA)cout<<x<<" ";
    cout<<endl;
    cout<<"Subset 2: ";
    for(int x:bestB)cout<<x<<" ";
    cout<<endl;
    cout<<"Minimum Difference: "<<mindiff<<endl;

    return 0;
}
