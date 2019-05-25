#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

int main(){
    /*Complete Search*/
    /*It is the general method of brute forcing solutions to the 
    problem. It is a good technique if there is enough time to got 
    through all the solutions. Otherwise it is better to use other 
    techniques, such as greedy algorithms or dynamic programming*/

    /***Generating subsets***/
    /*There are two common methods for doing this: performing a recurive 
    search or exploiting the bit representation of integers*/
    /**Method 1 - recurisive approach**/
    /*The function matains a vector called subset that will contain the
    elements of each subset*/
    /*The search begins when the function is called with paramenter 0*/
    /*When the function is called with parameter k, it decides whether
    to accept the element k in the subset or not and then calls itself
    with*/
    void search(int k){
        if(k == n){
            // process subset
        } else {
            search(k+1);//does not include k in subset since k is not put
            subset.push_back(k);//puts k to include k in subset
            search(k+1);//includes k in the subset
            subset.pop_back();
        }
    }
    /**Method 2 - using bit representation**/
    /*Each subset of a set of n elements can be represented as a 
    sequence of bits. The ones in the bit sequence indicate which 
    elements are included in the subset*/
    /*The last bit corresponds to index 0 and second last to index 1
    e.g: 25 is 11001 which corresponds to {0,3,4}*/
    for(int b = 0; b < (1<<n); b++){ // the << represent a bitshift left
        //process subset
    }
    /*The following code shows how we can find the elements of a subset
    that corresponds to bit sequence*/
    for(int b = 0; b < (1<<n); b++){//total number of subsets is accessed
        vector<int> subset;
        for(int i = 0; i < n; i++){
            /*This(the if) says that if a number belongs to the subset
            then it is added*/
            if (b&(1<<i)) subset.push_back(i);//only numbers that pass
                                            //the bit operation are added
        }
    }

    /***Generating permutations***/
    /*There are two approaches - recursion and iteration*/
    /**Method 1 - recursive approach**/
    /*The following function goes through elements of the set
    {0,...,n-1}. The function builds a vector called permutation that
    contains the permutations and it starts when search() is called
    without parameters*/
    void search(){
        if(permutation.size() == n){
            // process permutation
        } else {
            for(int i = 0; i < n; i++){
                //chosen indicates which vals are already in the permuation
                if (chosen[i]) continue;
                chosen[i] = true;
                permutation.push_back(i);
                search();
                chosen[i] = false;
                permutation.pop_back();
            }
        }
    }
    /**Method 2**/
    /*Another method for generating permutations is to begin with
    {0,1...,n-1} and repeatedly use a function that constructs the 
    next permutation in increasing order*/
    //you can use the C++ standard library function next_permutation
    //for this (it changes the order of the vector and returns state)
    vector<int> permutation;
    for (int i = 0; i < n; i++){
        permutation.push_back(i);
    }
    do {
        //process permutation
    } while (next_permutation(permutation.begin(),permutation.end());   

    /*Backtracking*/
    /*A backtracking algorithm begins with an empty solution and 
    extends the solution step by step. The search is recursive.*/
    /*As an example consider the number of ways n queens can be placed
    on an nXn chessboard so that no two queens attack each other*/
    /*The problem can be solved by backtracking by placing queens
    to the board row by row*/
    //The algorithm is implemented below
    //refer to page 61 of csesbook.pdf
    void search(int y){
        if(y==n){
            count++;
            return;
        }
        for (int x = 0; x < n; x++){
            if(column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
            column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
            search(y+1);
            column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
        }
    }
    /*Pruning the search*/
    /*It is when you prune non-extendable solutions earlier on in the
    implementation. Below we shall discuss how backtracking and pruning
    can be applied to a path algorithm of an nXn grid that traverses
    all the squares (from top left to bottom right)*/
    /*Basic Algorithm - use backtracking to generate all valid paths
    without optimization*/
    /*Optimization 1 - there are always two paths that are symmetric
    about the diagonal and in any solution we first move one step
    down or to the right. So if we pick only one first move , either one
    step down (or right). We can generate all solutions fort that case
    and multiply by two*/
    /*Optimization 2 - if the path reaches the lower right square before
    it has visited then it is not a valid solution. So we can prune 
    all paths that visit the lower right too early*/
    /*Optimization 3 - if the path touches a wall and can turn either
    left or right, then it can't visit the rest of the squares anymore*/
    /*Optimization 4 - Generalize Optimization 3. Basically if the path
    cannot continue forward but can turn either left or right then the
    solution cannot be valid*/
    /*After the optimization the algorithm was 1000 times faster.
    This is usually the case in backtracking (Note: optimizations
    at the first few steps of the algorithm are especially useful)*/

    /*Meet in the middle*/
    /*It is a technique where the search space is divided into two 
    parts of almost equal sizes and seperate searches are performed 
    on each of the pieces and the results are combined to obtain the
    final result*/
    /*As an example consider the problem where we are given a list 
    of n numbers and a number x, and we want to find if there are some
    numbers from the list that add up to x*/
    /*A simple algorithm would be to compute all the subsets of the
    element and check which of them add up to x. The running time
    of such an algorithm would be O(2^n), because there are 2^n subsets.
    But if we use the meet in the middle technique then we can achieve a 
    more efficient algorithm that runs in O(2^(n/2)).*/
    /*The algorithm works by dividing the list into two lists (say
    A and B) and generating the sums of the subsets of A and B and 
    store them in two lists (Sa and Sb) and finally checking if an
    element in Sa plus and element in Sb would sum to x.*/
    /*We can implement this algorithm in O(2^(n/2)). First we generate
    sorted lists Sa and Sb which can be done in O(2^(n/2)) time using
    a merge-like technique. After this we can check the sums in O(2^(n/2))
    time.*/
    return 0;
}

