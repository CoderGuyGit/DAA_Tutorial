#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"No of license(s):";
    cin>>n;

    vector<double> r(n,0);
    cout<<"Rates:";
    for(int i=0;i<n;i++)cin>>r[i];
    sort(r.rbegin(),r.rend());
    cout<<"Optimal choice:";
    for(int i=0;i<n;i++)cout<<r[i]<<" ";
    cout<<endl;
    return 0;
}