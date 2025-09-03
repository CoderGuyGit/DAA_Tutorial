#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> getTowers(vector<int> houses){
    if(houses.size()==0)return {};
    
    vector<int> towers;

    sort(houses.begin(),houses.end());

    int temp=houses[0]+4;
    towers.push_back(temp);

    for(int i=0;i<houses.size();i++){
        if(houses[i]-temp>4){
            temp=houses[i]+4;
            towers.push_back(temp);
        }
    }

    return towers;
}

int main(){
    int n;
    cout<<"Enter the number of houses:";
    cin>>n;
    
    vector<int> houses(n,0);
    cout<<"Enter the location of houses:";
    for(int i=0;i<n;i++)cin>>houses[i];

    vector<int> towers=getTowers(houses);

    cout<<"Towers : [ ";
    for(int i=0;i<towers.size();i++)cout<<towers[i]<<" ";
    cout<<"]"<<endl;

    return 0;
}