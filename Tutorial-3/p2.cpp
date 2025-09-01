#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;


int distance(pair<int,int> a,pair<int,int> b,pair<int,int> c){
    //(x2-x1)(y-y1)=(y2-y1)(x-x1)
    
    return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);

}

void convexHull(set<pair<int,int>>& hull,vector<pair<int,int>> points,pair<int,int> lp,pair<int,int> rp,int side){
    int indexpt=-1;
    int maxd=0;

    for(int i=0;i<points.size();i++){
        int d=distance(lp,rp,points[i]);
        if(abs(d)>maxd && side*d>0){
            maxd=abs(d);
            indexpt=i;
        }
    }

    if(indexpt==-1){
        hull.insert(lp);
        hull.insert(rp);
        return;
    }

    convexHull(hull,points,points[indexpt],lp,-distance(lp,rp,points[indexpt]));
    convexHull(hull,points,points[indexpt],rp,-distance(rp,lp,points[indexpt]));

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

    set<pair<int,int>> hull;
    convexHull(hull,points,points[0],points[n-1],1);
    convexHull(hull,points,points[0],points[n-1],-1);

    cout<<"Convex hull:"<<endl;
    for(pair<int,int> p:hull)cout<<"("<<p.first<<","<<p.second<<")"<<endl;
    return 0;
}