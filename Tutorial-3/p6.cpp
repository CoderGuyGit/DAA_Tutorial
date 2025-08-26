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

vector<vector<int>> mergelines(vector<vector<int>> Left,vector<vector<int>> Right){
    vector<vector<int>> temp;
    int l=0,r=0;
    int h1=0,h2=0;

    while(l!=Left.size() && r!=Right.size()){
        int x;
        int maxh;
        if(Left[l][0]<Right[r][0]){
            x=Left[l][0];
            h1=Left[l][1];
            l++;
        }
        else if(Left[l][0]>Right[r][0]){
            x=Right[r][0];
            h2=Right[r][1];
            r++;
        }
        else{
            x=Left[l][0];
            h1=Left[l][1];
            l++;
            h2=Right[r][1];
            r++;
        }
        maxh=max(h1,h2);

        if(temp.empty() || temp[temp.size()-1][1]!=maxh)
            temp.push_back({x,maxh});
    
    }
    while(l!=Left.size()){
        temp.push_back({Left[l][0],Left[l][1]});
        l++;
    }
    while(r!=Right.size()){
        temp.push_back({Right[r][0],Right[r][1]});
        r++;
    }
    return temp;    
}

vector<vector<int>> skyline(vector<vector<int>> build,int start,int end){
    if(start==end)return {{build[start][0],build[start][2]},{build[start][1],0}};

    return mergelines(skyline(build,start,(start+end)/2),skyline(build,(start+end)/2+1,end));
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

    vector<vector<int>> ans=skyline(build,0,n-1);
    
    
    cout<<"The skyline formed by given builldings is:"<<endl;
    for(auto x:ans){
        cout<<"x="<<x[0]<<" , h="<<x[1]<<endl;
    }
    return 0;
}