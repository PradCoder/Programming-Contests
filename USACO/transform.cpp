/*
ID: 2010pes1
TASK: milk2
LANG: C++
*/

#include "bits/stdc++.h"
#include <cstdio>

using namespace std;

/*
#1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
#2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
#3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
#4: Reflection: The pattern was reflected horizontally (turned into a mirror 
    image of itself by reflecting around a vertical line in the middle of the image).
#5: Combination: The pattern was reflected horizontally and then subjected to one 
    of the rotations (#1-#3).
#6: No Change: The original pattern was not changed.
#7: Invalid Transformation: The new pattern was not obtained by any of the above methods.
*/


int mod(int n,int j){
    while(j < 0){
        j += n;
    }
    return (j % n);
}

int solve(int n, vector<string> va, vector<string> vb){
    int mi = 8;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){

            if(v[i % n][j % n] == v[i%n][j%n]){
                mi = min(mi,1);
            }else if (v[i%n][j%n] == v[i%n][j%n]){
                mi = min(mi,2);  
            }else if (v[i%n][j%n] == [i%n][j%n]dfs){
                mi = min(mi,3); 
            }else if (sdfsf == sdfs){
                mi = min(mi,4); 
            }else if (
        }
    }
    return mi;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    ifstream fin ("beads.in");
    ofstream fout ("beads.out");

    int n;
    fin >> n;
    vector<string> vb,va;
    vb = vector<string>(n,"");
    va = vector<string>(n,"");

    for(int i = 0; i < n; i++){
        fin >> vb[i]; 
    }

    for(int i = 0; i < n; i++){
        fin >> va[i];
    }

    fout << solve(n, vb, va);
    return 0;
}
