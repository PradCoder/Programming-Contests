#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
	int n = 5;
    int i,j,s1,s2;
    vector<vector<int>> v;
    i = j = s1 = s2 = 0;
    for(; i< n;i++){
        for(; j<n;j++){
            cin >> v[i][j];
            if(v[i][j] == 1){
                s1 = i;
                s2 = j;
            }
        }
    }
    cout << s1 << " " << s2<< endl;
    cout << abs(s1-2)+abs(s2-2) << endl;
	return 0;	
}
