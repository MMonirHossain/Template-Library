#include<bits/stdc++.h>
using namespace std;




//segment tree area start
#define mx 100005
int arr[mx];
int tree[mx*4];

void init_segment_tree(int node,int left,int right){

    if(left==right){
        tree[node]=arr[left];
        return;
    }

    int mid=(left+right)>>1;
    int nd=node<<1;
    init_segment_tree(nd,left,mid);
    init_segment_tree(nd+1,mid+1,right);
    ///Modify the below line as needed
    tree[node]=tree[nd]+tree[nd+1];//this is for sum

}
///call with update_node(1,1,n,node,newval)
int node_no,value;//can be used as globally to reduce overhead of passing parameter
void update_node(int node,int left,int right,int node_no,int value){
    if(left>node_no || right<node_no){return;}//out of bound case
    if(left>=node_no && right<=node_no){tree[node]=value;return;}

    int mid=(left+right)>>1;
    int nd=node<<1;
    update_node(nd,  left, mid,  node_no,value);
    update_node(nd+1,mid+1,right,node_no,value);

    tree[node]=tree[nd]+tree[nd+1];
}
///call with- query(1,1,n,i,j); where i,j range
int range_i,range_j;//can be used for replace i,j
int query(int node,int left,int right,int i,int j){

    if(left>j || right<i){return 0;}//out of bound case
    if(left>=i && right<=j){return tree[node];}//Match case

    int mid=(left+right)>>1;
    int nd=node<<1;
    int val1=query(nd,  left, mid,  i,j);
    int val2=query(nd+1,mid+1,right,i,j);
    //Modify as needed

    return val1+val2;
}


int main(){

int n=10;
init_segment_tree(1,1,n);

return 0;
}
