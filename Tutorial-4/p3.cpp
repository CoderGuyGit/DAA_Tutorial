#include<bits/stdc++.h>

using namespace std;

void swap(pair<char,int> &a,pair<char,int> &b){
    pair<char,int> temp=a;
    a=b;
    b=temp;
}

void heapify(vector<pair<char,int>> &heap,int index){
    int l=2*index+1;
    int r=2*index+2;

    int min=index;
    if(l<heap.size() && heap[l].second<heap[min].second){
        min=l;
    }
    if(r<heap.size() && heap[r].second<heap[min].second){
        min=r;
    }

    if(min!=index){
        swap(heap[min],heap[index]);
        heapify(heap,min);
    }
}

void buildHeap(vector<pair<char,int>> &heap){
    for(int i=heap.size()/2-1;i>=0;i--){
        heapify(heap,i);
    }
}

pair<char,int> extractMin(vector<pair<char,int>> &heap){
    pair<char,int> temp=heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    if(!heap.empty()) heapify(heap,0);
    return temp;
}

void insert_heap(vector<pair<char,int>> &heap,pair<char,int> t){
    heap.push_back(t);
    int i=heap.size()-1;

    while(i>0){
        int parent = (i-1)/2;
        if(heap[parent].second<heap[i].second)break;
        swap(heap[parent],heap[i]);
        i=parent;
    }

}

string HuffmanCode(vector<pair<char,int>> mp){
    vector<pair<char,int>> heap=mp;
    buildHeap(heap);
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