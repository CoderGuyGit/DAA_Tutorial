#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> convexHull(vector<pair<int,int>> points,int start,int end){
}

int main(){
    int n;
    int temp;

    cout<<"Enter count of the points:";
    cin>>n;
    vector<pair<int,int>> points(n,{0,0});
    
    cout<<"Enter all points:"<<endl;
    for(int i=0;i<n;i++){
        cin>>points[i].first >> points[i].second;
    }

    sort(points.begin(),points.end());
    vector<pair<int,int>> hull;
    hull=convexHull(points,0,n-1);

    cout<<"Convex hull:"<<endl;
    for(int i=0;i<n;i++)cout<<"("<<hull[i].first<<","<<hull[i].second<<")"<<endl;
    return 0;
}