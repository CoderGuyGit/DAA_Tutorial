#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return ((a.first)*1.0)/(a.second)>((b.first)*1.0)/(b.second);
}

double fracKnapsack(vector<pair<int,int>> S,int W){
    sort(S.begin(),S.end(),compare);
    double profit=0;
    
    int i=0;
    while(i<S.size() && S[i].second<=W){
        profit+=S[i].first;
        W-=S[i].second;
        i++;
    }
    if(i<S.size() && W!=0){
        profit+=(S[i].first*W)/(double)(S[i].second);
    }
    return profit;
} 

int main(){
    int W;
    cout<<"Enter knapsack capacity:";
    cin>>W;
    int n;
    cout<<"Enter the number of items:";
    cin>>n;
    vector<pair<int,int>> S(n,{0,0});
    cout<<"Input item value and weight:\n";

    for(int i=0;i<n;i++)cin>>S[i].first>>S[i].second;

    cout<<"Optimum profit is:"<<fracKnapsack(S,W);

}