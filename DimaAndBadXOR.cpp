#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define F first
#define S second
#define PG push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,b,c,d;
	string x;
	cin >> a >> b; 
	vector<vector<int>> vec(a, vector<int>(b));
 	REP(i,0,a-1){
		cin >> c >> d;
		vec[i][0] = c;
		vec[i][1] = d;
	} 
	
	int best = 0;
	REP(i,0,a-1){
		REP(j,o,b-1){
			best ^= vec[i][j]	
		}
	}
	cout << a << " " << b << " " << x << "\n";
}
