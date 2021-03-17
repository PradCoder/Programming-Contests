#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;
int main(){
	int n;
	cin >> n;
	long long ans = 2*3*pow(4,n-2) + (n-3)*9*pow(4,n-3);
	cout << ans << endl;
}
