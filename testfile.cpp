//TO RUN: g++ -std=c++11 -O2 -Wall testfile.cpp -o testfile
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//type definitions
	typedef vector<int> vi;
	typedef unsigned int ui;

	vi one = {0,0,0,0,0};
	
	for(ui i = 0; i < one.size(); i++)
	{
		cout<< one[i] <<" ";
	}
	cout<<endl;
	vector<int> v = {4,2,5,3,5,8,3};
	sort(v.begin(),v.end());

	for(int i = 0;i < 7;i++)
		cout<<v[i]<<" ";
	cout<<"\n";
	sort(v.rbegin(),v.rend());
	for(int i = 0;i < 7;i++)
		cout<<v[i]<<" ";
	cout<<"\n";
	int x = 7;
	x = (2+9)/x;
	cout << x << "\n";

	set<int> s = {2,4,5,6,8};
	auto it = s.lower_bound(3);
	cout << *it << "\n";
	it =  s.upper_bound(3);
	cout << *it << "\n";
	cout << (1<<4) << "\n";
	cout << (3&2)<<"\n";
	/*cout << "INF = " << INF << "\n";  
	INF is only a placeholder for a big value*/
	vector<int> out= {90,80,7};
	cout<<out.size()<<endl;

	vi array = {6,2,5,1,7,4,8,3};	
	vi length = {0};
	int maxi = 1;
	
	/*try to run in nlogn time*/
	int n = array.size();
	for(int k=0;k<n;k++){
		length[k] = 1;
		for(int i=0;i<k;i++){
			if(array[i]<array[k]){
				length[k] = max(length[k],length[i]+1);
			}
		}
		(length[k]>maxi) ? (maxi = length[k]) : (maxi = maxi);
	}
	cout<<maxi<<endl;
	
	set<int> myset = {1,2,3,4};
	cout<<*myset.end()<<endl; 

	//Edit distance
	string xin= "PESARA"; string yin = "AMARASEKERA";
    //getline(cin,xin);getline(cin,yin);
    int a = xin.size();int b = yin.size();
    vector<vector<int>> distance(a+1,vector<int>(b+1));
    distance[0][0] = 0;
    int cost = 0;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
			if(i>0&&j>0){
            	(xin[i-1]==yin[j-1]) ? (cost=0):(cost=1);
				distance[i][j] = min({distance[i][j-1]+1,distance[i-1][j]+1,distance[i-1][j-1]+cost});
			}else{
				if (i==0 && j > 0) distance[i][j] = distance[i][j-1] + 1;
				if (i>0 && j == 0) distance[i][j] = distance[i-1][j] + 1;
			}
        }
    }
    /*printing vector of vectors*/
    for(vector<int> xout : distance){
        for(int elem : xout){
            printf("%i ",elem);
        }
        printf("\n");
    }
	printf("Max edits: %i\n",distance[a][b]);
	
	//Counting tilings
	n =4; int m=7; long double ans = 1;
    //cin>>n>>m;
    for(int a=1;a<=ceil(n/2);a++){
        for(int b=1;b<=ceil(m/2);b++){
            ans = ans*4*(pow((cos(M_PI*a/(n+1))),2)+pow((cos(M_PI*b/(m+1))),2));
        }
    }
    printf("%i \n",(int) ans);

	//binary stuff again
	int k =8;
	printf("%i %i %i ",k,-k,k&-k);
	k-=k&-k;
	printf("%i\n",k);
	printf("%i\n",(-7)/2);

	pair<int,int> best[2];
	best[0] = {0,0};
	best[1] = {0,-2};
	best[0] = min(best[0],best[1]);
	printf("pairs: %i %i\n",best[0].first,best[0].second);//best only compares the first elements that are different
	return 0; 
}
