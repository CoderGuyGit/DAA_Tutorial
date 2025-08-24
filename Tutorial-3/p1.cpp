#include<iostream>
using namespace std;

int countAndMergeSort(int *arr,int start,int end){
    int mid=(start+end)/2;
    int n=end-start+1;
    int temp[n];

    int count=0;
    int l=0,r=mid+1;
    int i=0;
    
    while(l<=mid && r<=end){
        if(arr[l]>arr[r]){
            temp[i++]=arr[r++];
            count+=mid-l+1;
        }
        else temp[i++]=arr[l++];
    }
    while(l<=mid)temp[i++]=arr[l++];
    while(r<=end)temp[i++]=arr[r++];

    for(int j=start;j<=end;j++)arr[j]=temp[j-start];
    return count;
}

int countInversions(int *arr,int start,int end){
    int n=(end-start+1);    //n is the size of array
    //Recursion breaker;
    if(n<=1)return 0;
    else if(n==2)return (int)arr[start]>arr[end];

    int count=countInversions(arr,start,(start+end)/2)+countInversions(arr,(start+end)/2+1,end);
    count+=countAndMergeSort(arr,start,end);

    return count;
}

int main(){
    int n;
    cout<<"Enter the size of your array:";
    cin>>n;
    int A[n];

    for(int i=0;i<n;i++){
        cout<<"A["<<i<<"] =";
        cin>>A[i];
    }
    
    cout<<"Number of inversions:"<<countInversions(A,0,n-1);

    return 0;
}