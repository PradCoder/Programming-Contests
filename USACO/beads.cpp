/*
ID: 2010pes1
TASK: beads
LANG: C++
*/
#include "bits/stdc++.h"

using namespace std;
/*
Collect Beads of 2 colours from opposite ends
White beads can be colored anything.
*/

int mod (int v, int n){
    return (n + (v % n)) % n;
}
         //Find first point of difference
         //Find colour at that point
         //Travel until colour changes
         //Input colour, start index, and size into a triple and store
         //Create a list of segments of the necklace
         //Add together segments of white with one colour until the opposite color
         //segment is found add until another color change
         //Find maximum arrangement using new information
         //return maximum

int solve(int n, string str){
    string newstr = "";
    for(int i = 0; i < n;i++){
        if(str[mod(i,n)] != str[mod(i+1,n)]){
            newstr = newstr + str[i] + "|";
        }else{
            newstr = newstr + str[i];
        }
    }
    vector<string> segments = vector<string>();
    for (int i = 0; i < newstr.length();){
        string segment = "";
        int j = i;
        while((newstr[j] != '|') && j < newstr.length()){
            segment = segment + newstr[j];
            j++;
        }
        segments.push_back(segment);
        i = j+1;
    }
    cout << newstr << " " << newstr.length() << "\n";
    if(segments[0][0] == segments[segments.size()-1][0]){
        segments[0] = segments[segments.size()-1] + segments[0];
        segments.pop_back();
    }

    for(string j: segments){
        cout << j << " ";
    }

    cout << "\n";
    
    int nSg = segments.size();
    char state = segments[0][0];
    int idmptnce = 0;
    for(int i = 0; i < nSg; i++){
        if(segments[mod(i,nSg)][0] != 'w'){
            state = segments[mod(i,nSg)][0];
        }
        int part1 = 0;
        int j = i;
        while((state == 'w' || segments[mod(j,nSg)][0] == 'w' || state == segments[mod(j,nSg)][0]) && part1 + segments[mod(i,nSg)].length() <= str.length()){
            part1 = part1 + segments[mod(i,nSg)].length();
            j = mod(j+1,nSg);
        }
        idmptnce = max(idmptnce, part1);
    }
    cout << idmptnce << "\n";
    return 0;
}

int solve1(int n, string str){
    string newstr;
    newstr = str+str;
    char charState = '\0';
    int intState = 0;
    int charCount;

    strState = 0;

    for(int i = 0; i < 2*n; i++){

        if(newstr[i] != 'w'){
            prevState =  
        }
        if(newstr[i] == 'r' || newstr[i] == 'b'){
            strState++;
        }
        charCount = ;
        if(strState == 2){
        }
    }
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    ifstream fin ("beads.in");
    ofstream fout ("beads.out");
    int n;
    string str;

    fin >> n;
    fin >> str;
    fout << solve1(n,str) << "\n";
    return 0;
}
