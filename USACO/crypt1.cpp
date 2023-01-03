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

bool containment(vector<int> space, string str){
    bool is_in = true;
    for (int i = 0; i < str.length(); i++){
        int a = (str[i]-'0'); 
        if(str == "444"){
            cout << "looped " << a << " " << space.size() << "\n";
            for (auto i : space) {
                cout << i << "\n"; 
            }
            cout << "Und stuff: " << (find(space.begin(), space.end(), a) != space.end()) << "\n";
            cout << "Ended loop\n";
        }
        if(find(space.begin(), space.end(), a) != space.end()){
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
    
    vector<vector<int>> vec(n*n*n*n*n,{0,0,0,0,0});
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                for (int l = 0; l < n; l++){
                    for (int m = 0; m < n; m++){
                        //get values
                        vector<int> temp = {v[i], v[j], v[k], v[l], v[m]};
                        //store the set
                        vec[(i*n*n*n*n)+(j*n*n*n)+(k*n*n)+(l*n)+m] = temp;
                        //cout << (i*n*n*n*n)+(j*n*n*n)+(k*n*n)+(l*n)+m << "\n";
                        string a, b, c, d, e;
                        //put values in one place
                        a = to_string(v[i]);
                        b = to_string(v[j]);
                        c = to_string(v[k]);
                        d = to_string(v[l]);
                        e = to_string(v[m]);
                        //put temp
                        vector<int> space = {v[i], v[j], v[k], v[l], v[m]};
                        //cout << a << " " << b << " " << " " << c << " " << d << " " << e << endl;
                        //values
                        int abc, de; // abc and de don't need to be checked as they are
                                     // only contain elements from the set
                        
                        abc = stoi(a+b+c);
                        de = stoi(d+e); 

                        if (abc == 222 || (a == "2" && b == "2" && c == "2")){
                            cout << a << " " << b << " " << c << "\n";
                            cout << abc << "HERE!!!!" <<  "\n";
                        }else if(de == 22){
                            cout << de << "\n";
                        }

                        string p1s, p2s; //partial products
                        p1s = to_string(abc * stoi(e)); 
                        p2s = to_string(abc * stoi(d));
                        cout << "Outside\n";
                        cout << p1s << " " << p2s  << "\n";
                        if (p1s == "444" && p2s == "444"){
                            cout << "Inside\n";
                            cout << p1s << " " << p2s << "\n";
                            cout << space.size() << "\n";
                            cout << "Regenschrim: " << true << containment(space,p1s) << " " << containment(space,p2s) << "\n";
                        }
                        //debug containment 
                        if(containment(space, p1s) && containment(space, p2s)){
                            string str_fin;
                            str_fin = to_string(stoi(p1s) + stoi(p2s)*10);
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
