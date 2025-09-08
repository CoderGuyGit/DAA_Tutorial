#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    unsigned int n;
    cout<<"The travel distance of car on full tank: ";
    cin>>n;

    int d;
    cout<<"Distance:";
    cin>>d;

    int m;
    cout<<"No of petrol pumps:";
    cin>>m;
    vector<int> p(m,0);

    cout<<"Locations of petrol pumps:\n";
    for(int i=0;i<m;i++)cin>>p[i];

    sort(p.begin(),p.end());

    int start=n;
    int i=0;
    vector<int> ans;
    bool flag = false;

    while(start<d){
        int last=-1;

        while(i<m && p[i]<=start){
            last = p[i];
            i++;
        }
        if(last== -1){ // no reachable pump
            flag=true;
            break;
        }
        ans.push_back(last);
        start=last+n;
    }

    cout<<"Required stations:";
    if(!flag) for(int x:ans)cout<<x<<" ";
    else cout << "Not Possible!";
    cout<<endl;

    return 0;
}
