#include "bits/stdc++.h"

using namespace std;

int main(){
    int i;
    int count = 0;
    cin >> i;
    while(i--){
        int inp;
        cin >> inp;
        if (inp & 1){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
