#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct{
    int x;
    int y;
}point;

vector<point> convexHull(vector<point> points,int start,int end){
    int n=end-start+1;

    if(n<=5){
        for(int i=start;i<=end;i++){
            for(int j=i+1;j<=end;j++){
                ;
            }
        }
    }
}

int main(){
    int n;
    int temp;

    cout<<"Enter count of the points:";
    cin>>n;
    vector<point> points(n,{0,0});
    
    for(int i=0;i<n;i++){
        cin>>points[i].x>>points[i].y;
    }

    vector<point> hull;
    sort(points.begin(),points.end());
    hull=convexHull(points,0,n-1);

    cout<<"Convex hull:"<<endl;
    for(int i=0;i<n;i++)cout<<"("<<hull[i].x<<","<<hull[i].y<<")"<<endl;
    return 0;
}