#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <math.h>


using namespace std;

vector<string> stringSplit(string str, char delim){
    vector<string> vs;
    int i = 0;
    string res = "";
    while(str[i] != '\0'){
        if(str[i] != delim){
            res += str[i];
        }else{
            vs.push_back(res);
            res = "";
        }
        i++;
    }
    vs.push_back(res);
    return vs; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<string> ops;
    stack<double> vals;
    string s;
    getline(cin,s);
    vector<string> stream = stringSplit(s,' ');
    int i = 0;
    int n = stream.size();
    while(i < n){
        s = stream[i];
        i++;
        if(s == "("){
            continue;
        }else if (s == "+"){
            ops.push(s);
        }else if (s == "-"){
            ops.push(s);
        }else if (s == "*"){
            ops.push(s);
        }else if (s == "/"){
            ops.push(s);
        }else if (s == "sqrt"){
            ops.push(s);
        }else if (s == ")"){
            string op = ops.top();
            ops.pop();
            double v = vals.top();
            vals.pop();
            if(op == "+"){
                v = vals.top() + v;
                vals.pop();
            }else if (op == "-"){
                v = vals.top() - v;
                vals.pop();
            }else if (op == "*"){
                v = vals.top() * v;
                vals.pop();
            }else if (op == "/"){
                v = vals.top() / v;
                vals.pop();
            }else if (op == "sqrt"){
                v = sqrt(v);
            }
            vals.push(v);
        }else{
            vals.push(stod(s));
        }
    }
    cout << vals.top() << endl;
    return 0;
}
