#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    
    char c;
    int freq;
    Node* left;
    Node* right;

    Node(char ch,int f){
        c=ch;
        freq=f;
        left=nullptr;
        right=nullptr;
    }
};

struct Compare{
    bool operator ()(Node* a,Node* b){
        return a->freq>b->freq;
    }
};

int getCost(Node* head,int depth=0){
    if(head==nullptr)return 0;
    if(head->c != '#')return depth * (head->freq);
    return getCost(head->left,depth+1)+getCost(head->right,depth+1);
}

int HuffmanCost(vector<pair<char,int>> mp){
    priority_queue<Node*,vector<Node*>,Compare> heap;
    for(auto x:mp)heap.push(new Node(x.first,x.second));


    while(heap.size()>1){
        Node* l=heap.top();
        heap.pop();
        Node* r=heap.top();
        heap.pop();

        Node* comb=new Node('#',l->freq+r->freq);
        if(l->freq>r->freq)swap(l,r);
        comb->left=l;
        comb->right=r;
        heap.push(comb);
    }

    Node* root=heap.top();
    return getCost(root);
}

int main(){
    vector<pair<char,int>> umap;
    char c;
    int f;
    char r='\0';
    while(r!='n' && r!='N'){
        cout<<setw(20)<<"\nEnter the character:";
        cin>>c;
        cout<<setw(20)<<"Enter it's frequency:";
        cin>>f;
        umap.push_back({c,f});

        
        cout<<"Continue?(y/n):";
        cin>>r;
    }

    cout<<"Total cost:"<<HuffmanCost(umap)<<endl;
    return 0;
}