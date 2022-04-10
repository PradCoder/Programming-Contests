#include "bits/stdc++.h"
#include <iostream>
#include <vector>

using namespace std;

string modStr(int b){
    string s = "";
    while(b--){
        s +="%d";
    }
    return s;
}

int main(){
	int a,b;
    string s;
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> s;
        char *token = strtok(s,"");
        vector<int> v;
        //This is kinda iffy
        sscanf(s.c_str(), modStr(b),v);
        cout << v;
    }
	return 0;	
}
