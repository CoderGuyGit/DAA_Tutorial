#include<bits/stdc++.h>
using namespace std;

int n;
int generated=0,pruned=0;
vector<int> board;

bool safe(int row,int col){
    for(int i=0;i<row;i++){
        if(board[i]==col || abs(board[i]-col)==abs(i-row))
            return false;
    }
    return true;
}

void solve(int row){
    if(row==n){
        cout<<"(";
        for(int i=0;i<n;i++){
            cout<<board[i]+1;
            if(i<n-1)cout<<",";
        }
        cout<<")"<<endl;
        return;
    }
    for(int col=0;col<n;col++){
        generated++;
        if(safe(row,col)){
            board[row]=col;
            solve(row+1);
        }else pruned++;
    }
}

int main(){
    cout<<"Enter n:"<<endl;
    cin>>n;
    board.assign(n,-1);
    solve(0);
    cout<<"\nTotal Nodes Generated:"<<generated<<endl;
    cout<<"Total Nodes Pruned:"<<pruned<<endl;
    return 0;
}
