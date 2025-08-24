#include<iostream>
using namespace std;

//Assuming all inputs are valid 1<k<n

void merge(int *a,int start,int end){
    int n=end-start+1;
    int temp[n];
    int mid=(start+end)/2;
    int l=start,r=mid+1;
    
    int i=0;
    while(l<=mid && r<=end){
        temp[i++]=a[l]<a[r]?a[l++]:a[r++];
    }
    while(l<=mid)temp[i++]=a[l++];
    while(r<=end)temp[i++]=a[r++];

    for(i=start;i<=end;i++)a[i]=temp[i-start];
}

void mergesort(int *a,int start,int end){
    int n=end-start+1;
    if(n==1)return;

    mergesort(a,start,(start+end)/2);
    mergesort(a,(start+end)/2+1,end);

    merge(a,start,end);
}

int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;

    int a[n];
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<n;i++)cin>>a[i];

    int k;
    cout<<"Enter the value of k:";
    cin>>k;

    mergesort(a,0,n-1);
    
    cout<<"k th smallest element is "<<a[k-1];
    return 0;
}