/*
ID: 2010pes1
TASK: crypt1
LANG: C++
*/
#include "bits/stdc++.h"
#include <string>
// This entire thing will take me an entire year if I plan on solving
// it solidly

using namespace std;

bool containment(set<int> space, string str){
    bool is_in = true;
    for (int i = 0; i < str.length(); i++){
        int a = (str[i]-'0'); 
        if(space.find(a) != space.end()){
            is_in = true; 
        }else{
            return false;
        }
    }
    return is_in;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ofstream fout("crypt1.out");
    ifstream fin("crypt1.in");    

    int n;
    fin >> n;
    vector<int> v = vector<int>(n,0);
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }

    int count = 0;
    
    vector<set<int>> vec(n*n*n*n*n,{0,0,0,0,0});
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                for (int l = 0; l < n; l++){
                    for (int m = 0; m < n; m++){
                        vec[(i*n*n*n*n)+(j*n*n*n)+(k*n*n)+(l*n)+m] = {v[i], v[j], v[k], v[l], v[m]};
                        string a, b, c, d, e;
                        a = to_string(v[i]);
                        b = to_string(v[j]);
                        c = to_string(v[k]);
                        d = to_string(v[l]);
                        e = to_string(v[m]);
                        set<int> space = {v[i], v[j], v[k], v[l], v[m]};
                        cout << a << " " << b << " " << " " << c << " " << d << " " << e << endl;
                        int abc, de; // abc and de don't need to be checked as they are
                                     // only contain elements from the set
                        abc = stoi(a+b+c);
                        de = stoi(d+e);

                        string p1s, p2s; //partial products
                        p1s = to_string(abc * stoi(e)); 
                        p2s = to_string(abc*stoi(d)*10);
                        
                        if(containment(space, p1s) && containment(space, p2s)){
                            string str_fin;
                            str_fin = to_string(stoi(p1s) + stoi(p2s));
                            if(str_fin.length() == 3 && p1s.length() == 3 && p2s.length() == 3 && containment(space, str_fin)){
                                count++;
                            }
                        }

                    }
                }
            }
        }
    }
    cout << containment({2,3,4,6,8}, "4884") << "\n"; 
    cout << count << "\n";
    return 0;
}
