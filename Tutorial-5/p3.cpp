#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter your string"<<endl;
    getline(cin,s);
    int n=s.length();


    //Making a dp table to check each palindrome substring

    vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)isPalindrome[i][i]=true;
    for(int i=0;i<n-1;i++)isPalindrome[i][i+1]=s[i]==s[i+1];
    
    for(int len=3;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            isPalindrome[i][j]=s[i]==s[j] && isPalindrome[i+1][j-1];
        }
    }

    //Solving using bottom up memomtization O(n3)

    vector<vector<int>> cuts(n,vector<int>(n,INT_MAX));
    vector<vector<int>> split(n,vector<int>(n,0));

    for(int i=0;i<n;i++)cuts[i][i]=0;
    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            if(isPalindrome[i][j])cuts[i][j]=0;
            else{
                for(int k=i;k<j;k++){
                    int temp=1+cuts[i][k]+cuts[k+1][j];
                    
                    if(temp<cuts[i][j]){
                        cuts[i][j]=temp;
                        split[i][j]=k;
                    }
                }
            }
        }
    }

    cout<<"Minimum number of cuts needed="<<cuts[0][n-1];

    return 0;
}