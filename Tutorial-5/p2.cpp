#include<bits/stdc++.h>
using namespace std;

int min3(int a,int b,int c){
    if(a<=b && a<=c)return a;
    if(a<=b && c<=a)return c;
    if(a>=b && b<=c)return b;
    if(a>=b && b>=c)return c;
}

int main(){
    string subject,target;
    cout<<"Enter your string:"<<endl;
    getline(cin,subject);

    cout<<"Enter the target string:"<<endl;
    getline(cin,target);

    int n=subject.size(),m=target.size();
    vector<vector<int>> edit_distance(n+1,vector<int>(m+1,INT_MAX));

    //Base condition
    for(int i=0;i<m+1;i++)edit_distance[0][i]=i;    // comparing null string.SO i inserts
    for(int i=0;i<n+1;i++)edit_distance[i][0]=i;    //Target is null.SO delete all

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(subject[i]==target[j])edit_distance[i][j]=edit_distance[i-1][j-1];
            else{
                edit_distance[i][j]=min3(edit_distance[i-1][j-1],edit_distance[i-1][j],edit_distance[i][j-1])+1;
            }
        }
    }

    cout<<"Minimum distance:"<<edit_distance[n][m]<<endl;
    return 0;
}