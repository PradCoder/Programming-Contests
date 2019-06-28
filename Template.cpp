/*Author PradCoder*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct TNode{
    int val;
    TNode* right;
    TNode* left;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream inFile;
    ofstream outFile;

    inFile.open("input.txt");
    outFile.open("output.txt");
    int n;

    inFile>>n;
    outFile<<n<<" ";
}