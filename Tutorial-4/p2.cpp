#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
}

vector<int> schedule(vector<pair<int,int>> tasks){
    sort(tasks.begin(),tasks.end(),compare);//Sort by highest profit
    
    int max_d=0;
    for(int i=0;i<tasks.size();i++)
        if(tasks[i].first>max_d)max_d=tasks[i].first;
    
    vector<int> jobs(max_d,0);  //stores the job no

    for(int i=0;i<tasks.size();i++){
        for(int j=tasks[i].first-1;j>=0;j--){
            if(jobs[j]==0){
                jobs[j]=tasks[i].second;
                break;
            }
        }
    }
    
    return jobs;

}

int main(){
    int n;
    cout<<"Enter the count of jobs:";
    cin>>n;

    vector<pair<int,int>> tasks(n,{0,0});

    cout<<"Enter all deadline-profit pairs:"<<endl;
    for(int i=0;i<n;i++)cin>>tasks[i].first>>tasks[i].second;

    vector<int> jobs=schedule(tasks);

    cout<<"optimum approach would be:";
    cout<<"Start -> ";
    int count=0;

    for(int i=0;i<jobs.size();i++){
        cout<<jobs[i]<<" -> ";
        count+=jobs[i];
    }
    cout<<"End"<<endl;
    cout<<"Max profit:"<<count<<endl;

    return 0;
}
