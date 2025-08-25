#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of buildings:";
    cin>>n;

    int build[n][3];

    cout<<"For each building,enter left and right x coords and height of the building in order:"<<endl;
    for(int i=0;i<n;i++){
        cin>>build[i][0]>>build[i][1]>>build[i][2];
    }
    
    return 0;
}