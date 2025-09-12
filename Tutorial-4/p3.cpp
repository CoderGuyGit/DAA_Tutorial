#include<bits/stdc++.h>

using namespace std;

void swap(pair<char,int> &a,pair<char,int> &b){
    pair<char,int> temp=a;
    a=b;
    b=temp;
}

void heapify(vector<pair<char,int>> &heap,int index,int size){
    int l=2*index+1;
    int r=2*index+2;

    int min=index;
    if(l<size && heap[l].second<heap[min].second){
        min=l;
    }
    if(r<size && heap[r].second<heap[min].second){
        min=r;
    }

    if(min!=index){
        swap(heap[min],heap[index]);
        heapify(heap,min,size);
    }
}

void buildHeap(vector<pair<char,int>> &heap,int size){
    for(int i=size/2-1;i>=0;i--){
        heapify(heap,i,size);
    }
}

pair<char,int> extractMin(vector<pair<char,int>> &heap,int &size){
    pair<char,int> temp=heap[0];
    size--;
    swap(heap[0],heap[size]);
    heapify(heap,0,size);

}

string HuffmanCode(vector<pair<char,int>> mp){
    vector<pair<char,int>> heap=mp;
    buildHeap(heap,heap.size());

    for(int i=0;i<heap.size();i++){
        cout<<heap[i].second<<" ";
    }

    return "";
}

int main(){
    vector<pair<char,int>> umap;
    char c;
    int f;
    while(1){
        cout<<setw(20)<<"\nEnter the character:";
        cin>>c;
        cout<<setw(20)<<"Enter it's frequency:";
        cin>>f;
        umap.push_back({c,f});

        char r;
        cout<<"Continue?(y/n):";
        cin>>r;
        if(r=='n' || r=='N')break;
    }

    string hc=HuffmanCode(umap);
    return 0;
}