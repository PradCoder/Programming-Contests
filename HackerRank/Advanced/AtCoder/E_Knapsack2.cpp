//TODO: Figure out the proper optimization
#include "bits/stdc++.h"
#include <cstdint>


#define REP0(i,a,b)         for (int i = a; i < b; i++)
#define REP1(i,a,b)         for (int i = a; i <= b; i++)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;

const ll INF = 1e18;
const int32_t M = 1e9+7;
const int32_t MM=998244353;

/*
3 8
3 3
4 5
5 6

		0  1  2  3   4   5   6   7   8
3   30  0  0  0  30  30  30  30  30  30
4   50  0  0  0  30  50  50  50  80  80
5   60  0  0  0  30  50  60  60  80  90

Current one uses less memory but takes the same time
Find a way to improve the time taken (try using a greedy aproach)???
But greedy wouldn't work for DP problem. Since local optimum isn't global optimum.

				0 1  2  3   4  5 .. 1000000000
1000000000 10   0 0  0  0   0  0 .. 10

Try to do DP by value an minimize cost

W
0 ... W
0 ... V

1 1000000000
1000000000 10

1  1000000000
1000000000 10
            0 1 2 3 4 5 6 7 8 9 10
1000000000  0 0 0 0 0 0 0 0 0 0  1

3 8 -- Try to meet a weight of 8 by maximzong value
3 30 
4 50 
5 60
        W
	V	0  1  2  3   4   5   6   7   8
  3 30  0  0  0  30  30  30  30  30  30  [V]
W 4 50  0  0  0  30  50  50  50  80  80
  5 60  0  0  0  30  50  60  60  80  90

8   
   	    0    1    2     3 ....   30 31 ....  50  ....  60
30  3   0    0    0     0 ....   30 30 ....  30  ....  30   i-3
50 	4   0    0    0     0 ....   30 30 ..... 50  ....       i-4
60 	5   0    0    0     0 ....   30                         i-5

		0       1     2     3 ....     30 31 ....    50  .... 60 ... 1000
30  3   
50  4   50     50     50    50  ....   50 50 ....    50  ...  60 ...  
60  5   60     60     60    60  ....   60 60 ....    60  ...  60 ... INF      W - w >= 0 then <- min dp[i-1][i], vec[i] 

		0       1     2     3   ....     30 31 ....    50  .... 60 .... 1000 .... 2000 .... 3000
30  3   INF    INF    INF   INF ....    3  INF .....  INF   ... INF... INF    ...INF  .... INF      
50  4   INF    INF    INF   INF ....    3  INF  ....   4  ...  60 ...  
60  5   60     60     60    60  ....   60 60 ....    60  ...  60 ... INF      W - w >= 0 then <- min dp[i-1][i], vec[i] 


dp[i] - find the value with minimum weight
initial: maximize value by meeting weights
current: minimize weights by meeting value [i]


    0   1     2    3    4    5   6
1 3 0   3     3    3    3    3   3
2 4 0   3     4    7    7    7   7     
3 5 0   3     4    7    8    9   12

*/
bool compare(vl i, vl j){
	return (i[0] < j[0]);
}

long long solve(vector<vl> vec, int w, int n){
	ll sum_value = 0;
	for(auto i : vec){
		sum_value += i[1];
	}
	sort(vec.begin(), vec.end(), compare);
	for(auto i: vec){
		cout << i[0] << " " << i[1] << "\n";
	}
	vector<ll> dp = vector<ll>(sum_value+1,0); // current dp
	vector<ll> ps = vector<ll>(sum_value+1,0); // past states
	dp[0] = 0; //minimum value to have value 0
	for(int i = 0; i < n; i++){
		for(int j=0; j <= sum_value;j++){
			if(j - vec[i][1] < 0){
				/*
				Jump to where changes begin
				*/
				if(i==0){
					j=vec[i][1];
					dp[j] = vec[i][0];
				}else{
					j=vec[i][1];
					dp[j] = max(vec[i][0]+ps[j-vec[i][1]],ps[j]);
				}
			}else{
				/*
				Start updating states
				*/
				if(i==0){
					dp[j] =  vec[i][0];
				}else{
					dp[j] = max(vec[i][0]+ps[j-vec[i][1]],ps[j]);
				}
			}
		}
		ps = dp;
		REP1(j,0,sum_value){
			printf("%lld ", dp[j]);
		}
		printf("\n");
	}
	ll answer = sum_value;
	for (int i = 0; i<=sum_value; i++){
		if(dp[i] == w){
			answer = min(answer, (ll) i);
		}
	}

	return answer;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,w;
	cin >> n >> w;
	
	vector<vl> v = vector<vl>(n, vl(2,0));
	for(int i = 0; i < n; i++){
		cin >> v[i][0] >> v[i][1];
	}
	cout << solve(v,w,n) << "\n";

}

