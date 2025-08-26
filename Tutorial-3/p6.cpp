#include<iostream>
#include<vector>
using namespace std;

//Constraint:L,R,H are considered to be >0

void merge(vector<vector<int>> &build,int start,int end){
    int mid=(start+end)/2;
    vector<vector<int>> temp;

    int l=start,r=mid+1;
    while(l<=mid && r<=end){
        if(build[l][0]==build[r][0])
            temp.push_back(build[l][1]<build[r][1]?build[l++]:build[r++]);
        else
            temp.push_back(build[l][0]<build[r][0]?build[l++]:build[r++]);
    }
    while(l<=mid)temp.push_back(build[l++]);
    while(r<=end)temp.push_back(build[r++]);

    for(int i=0;i<temp.size();i++)build[i+start]=temp[i];
}

void sortByStart(vector<vector<int>> &build,int start,int end){
    if(start>=end)return;
    sortByStart(build,start,(start+end)/2);
    sortByStart(build,(start+end)/2+1,end);

    merge(build,start,end);
}

int main(){
    int n;
    cout<<"Enter the number of buildings:";
    cin>>n;

    vector<vector<int>> build(n,vector<int>(3,0));

    cout<<"For each building,enter left and right x coords and height of the building in order:"<<endl;
    for(int i=0;i<n;i++){
        cin>>build[i][0]>>build[i][1]>>build[i][2];
    }

    sortByStart(build,0,n-1);

    vector<int> temp(3,0);
    vector<vector<int>> ans;
    temp=build[0];
    ans.push_back({temp[0],temp[2]});

    for(int i=1;i<n;i++){
        if(temp[1]<build[i][0]){
            ans.push_back({temp[1],0});
            ans.push_back({build[i][0],build[i][2]});
        }
        else if(temp[2]<build[i][2])ans.push_back({build[i][0],build[i][2]});
    }
    
    
    cout<<"The skyline formed by given builldings is:"<<endl;
    for(auto x:ans){
        cout<<"x="<<x[0]<<" , h="<<x[1]<<endl;
    }
    return 0;
}