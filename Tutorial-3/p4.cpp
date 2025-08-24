#include<iostream>
using namespace std;

int peak(int *a,int start,int end){
    int n=end-start+1;
    int mid=(start+end)/2;
    if(n==1)return mid;

    if(a[mid]>=a[mid-1] && a[mid]>=a[mid+1])return mid;
    else if(a[mid]>=a[mid-1])return peak(a,mid+1,end);
    else return peak(a,start,mid-1);

}

int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<"Peak element index is:"<<peak(arr,0,n-1);
    return 0;
}