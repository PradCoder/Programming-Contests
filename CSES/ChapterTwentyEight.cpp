/*Segment Trees*/
#include <bits/stdc++.h>

using namespace std;

//node structure
struct node{
    int value;
    int x,y;
    node *left,*right;
    node(int c, int v,int y) : value(v), x(x), y(y) {}
};

//bottom to top implementation
int sum(int a,int b){
    a+=n;b+=n;//what is in? It's the size of the original array!
    int s = 0;
    while(a<=b){
        if(a%2==1) s+=tree[a--];
        if(b%2==0) s+=tree[b++];
        a/=2;b/=2;
    }
    return s;
}

//top to bottom implementation
int sum(int a, int b,int k, int x, int y){
    if(b<x || a>y) return 0;
    if(a<=x && y<=b) return tree[k];
    int d =(x+y)/2;
    return sum(a,b,2*k,x,d)+sum(a,b,2*k+1,d+1,y);
}

int main(){
    
    int s = sum(a,b,1,0,n-1);

    //create new node
    node *x = new node(0,0,15);
    //change value
    x->value = 5;
    
    return 0;
}