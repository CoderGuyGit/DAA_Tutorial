#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct{
    int x;
    int y;
}point;

int distanceSq(point a,point b){
    int d=(a.x*a.x+a.y*a.y)-(b.x*b.x+b.y*b.y);
    return max(d,-d);
}

vector<point> convexHull(vector<point> points,int start,int end){
    int n=end-start+1;

    if(n<=5){
        for(int i=start;i<=end;i++){
            for(int j=i+1;j<=end;j++){
                //Check if all points are above the line or below the line
                //(x2-x1)(y-y1)=(y2-y1)(x-x1)
                int a=points[j].x-points[i].x;
                int b=points[j].y-points[j].y;
                int up=0,down=0;
                vector<point> hull;
                int colinearIndex=j;
                for(int k=start;k<=end;k++){
                    if(a*(points[k].y-points[i].y)>b*(points[k].x-points[i].x))up++;
                    else if(a*(points[k].y-points[i].y)<b*(points[k].x-points[i].x))down++;
                    else {
                        up++;
                        down++;
                        if(distanceSq(points[k],points[i])>distanceSq(points[colinearIndex],points[i])){
                            colinearIndex=k;
                        }
                    }
                }

                if(up==n || down==n){
                    hull.push_back(points[i]);
                    hull.push_back(points[colinearIndex]);
                }
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