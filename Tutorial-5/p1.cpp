#include<iostream>
#include<vector>

using namespace std;

void printPattern(vector<vector<int>> s,int i,int j){
    if(i==j){
        cout<<"A"<<i;
        return;
    }
    cout<<'(';
    printPattern(s,i,s[i][j]);
    cout<<" x ";
    printPattern(s,s[i][j]+1,j);
    cout<<')';
}

long matrixChainMultiplyCost(int i,int j,vector<int>p){
    int n=p.size()-1;   //Number of matrices
    vector<vector<int>> m(n+1,vector<int>(n+1,0));   //Set up boundry condition m[i,i]=0
    vector<vector<int>> s(n+1,vector<int>(n+1,0));

    //WE have taken matrix index from 1 to n

    for(int i=1;i<=n;i++){
        s[i][i]=i;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            
            m[i][j]=__INT_MAX__;
            for(int r=i;r<j;r++){
                int temp=m[i][r]+m[r+1][j]+p[i-1]*p[r]*p[j];
                if(temp<m[i][j]){
                    m[i][j]=temp;
                    s[i][j]=r;
                }
            }
        }
    }
    cout<<"Optimal pattern:";
    printPattern(s,1,n);
    cout<<endl;
    return m[1][n];

}

int main(){
    int n;
    cout<<"Enter the number of matrices:";
    cin>>n;

    vector<int> p(n+1,0);
    cout<<"Enter the dimensions in sequence"<<endl;
    
    for(int i=0;i<n+1;i++)cin>>p[i];

    long cost=matrixChainMultiplyCost(1,n,p);
    cout<<"Minimum number of multiplications:"<<cost<<endl;
    

    return 0;
}