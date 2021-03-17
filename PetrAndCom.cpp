#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n;i++) cin>> v[i];
	for(int mask=0; mask < (1<<n); mask++){
		int sum = 0;
		for(int i=0; i<n; i++){
			if (mask&(1<<i)){
				sum += v[i];
			}else{
				sum -= v[i];
			}
		}
		sum = sum % 360;
		if(sum == 0){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;	
}
