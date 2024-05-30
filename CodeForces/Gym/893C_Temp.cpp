#include "bits/stdc++.h"
using namespace std;

#define intll long long
#define endl '\n'
#define TEST_CASE false

template<typename T>
void PRINT(vector<T>& arr){
    for (int i = 0; i < int(arr.size()); i++)
            //Cool new modifier
            cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr = vector<int>(5,0);
    for (int i = 0; i < int(arr.size()); i++)
            //Cool newline end
            cout << arr[i] << ((i == int(arr.size()) - 1) ? " \n": " ");
    return 0;
}