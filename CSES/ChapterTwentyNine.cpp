#include <bits/stdc++.h>

using namespace std;
typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()
int main(){
    P p = {4,2};
    cout<<p.X<<" "<<p.Y<<"\n"; // 4 2
    P v = {3,1};
    P u = {2,2};
    P s = v+u;
    cout << s.X <<" "<< s.Y<<"\n";// 5 3

    P a = {4,2};
    P b = {3,-1};
    cout << abs(b-a) << "\n"; //3.16228

    P v = {4,2};
    cout << arg(v) << "\n";// 0.463648
    v *= polar(1.0,0.5);
    cout << arg(v) << "\n"; // 0.963648

    P a = {4,2};
    P b = {1,2};
    C p = (conj(a)*b).Y; // 6


    return 0;
}