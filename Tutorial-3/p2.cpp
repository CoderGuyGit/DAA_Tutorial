#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> convexHull(vector<vector<int>> points,int start,int end){
    
}

int main(){
    int n;
    int temp;

    cout<<"Enter count of the points:";
    cin>>n;
    vector<vector<int>> points(n,vector<int>(2,0));
    
    for(int i=0;i<n;i++){
        cin>>points[i][0]>>points[i][1];
    }

    vector<vector<int>> hull;
    hull=convexHull(points,0,n-1);
    return 0;
}