#include <stdio.h>
#include <iostream>

using namespace std;

#define ll long long
#define N 1000005
ll p[N], f[N];


void sieve(){
	p[0] = 1;
	p[1] = 1;
        for(ll i = 2; i < N; i++){
		if(!p[i]){
			for(ll j = i*i;j<N;j+=i){
				p[j] = 1;
			}
		}
	}
}

bool fearful(ll x){
	int y = x;
	for(;y;y/=10){
		if(!(y%10)){
			return false;
		}
	}
	
	for(;x;){
		if(p[x]) return false;
		ll z = x;
		ll mod = 1;
		for(;z;z/=10)  mod *= 10;
		mod /= 10;
		
		x = x%mod;
	}
	
	return true;
}

int main(){
	sieve();
	for(ll i=2; i<N; i++){
		f[i] = f[i-1]+fearful(i);
	}
	ll T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}
