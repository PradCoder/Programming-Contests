#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned int n, fives, div;
    div = 5, fives = 0;
    cin >> n;

    while(n>=div){
        fives += n/div;
        div *= 5;
    }

    cout << fives << "\n";
    return 0;
}
