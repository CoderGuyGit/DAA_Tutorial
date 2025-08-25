#include<iostream>
using namespace std;

void partition(int *a,int start,int end,int &p,int &q){
    p=start,q=end;
    if(a[p]>a[q])swap(a[p],a[q]);

    int l=start+1,r=end-1;
    int i=start+1;

    while(i<=r){
        if(a[i]<a[p]){
            swap(a[i],a[l]);
            l++;
            i++;
        }
        else if(a[i]>a[q]){
            swap(a[i],a[r]);
            r--;
        }
        else i++;
    }

    l--;
    r++;
    swap(a[p],a[l]);
    swap(a[q],a[r]);
    p=l;
    q=r;
}

void dualQuickSort(int *a,int start,int end){
    if(start>=end)return;
    
    int p,q;//Left and Right pivot
    partition(a,start,end,p,q);
    dualQuickSort(a,start,p-1);
    dualQuickSort(a,p+1,q-1);
    dualQuickSort(a,q+1,end);
}

int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];
    cout<<"Enter the array elements:"<<endl;
    for(int i=0;i<n;i++)cin>>a[i];

    dualQuickSort(a,0,n-1);

    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)cout<<a[i]<<" ";

    return 0;
}