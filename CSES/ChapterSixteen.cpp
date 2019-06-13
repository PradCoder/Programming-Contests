/*Directed Graphs*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    /*
    TODO:Finish implementing Topological sort
    
    If a graph contains a cycle then it cannot be topologically sorted
    DFS can be used to both detect cycles and perform a sort
    */

   /*TDDO:Dynamic Programming*/
   //Dynamic programming probelems can be represented as a directed acyclic graph

   //TODO:Successor paths

   //TODO: Cycle Detection
   /*Floyd's Algorithm*/
   //TODO: Make a working implementation
    auto a = succ(x);
    auto b = succ(succ(x));
    while(a!=b){
        a = succ(a);
        b = succ(succ(b));
    }
    a=x;

    while(a!=b){
        a = succ(a);
        b = succ(b);
    }
    int first = a;

    b = succ(a);
    int length = 1;
    while(a != b){
        b = succ(b);
        length++
    } 

    return 0;
}