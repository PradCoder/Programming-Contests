#include "bits/stdc++.h"
using namespace std;
#define MAXN 100010
int n,m,k;
int a[MAXN];
void work()
{
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++)
		cin>>a[i];
	bool flag;
	long long tot=0;
	flag=0;
	tot=0;
	for (int i=1;i<=k;i++)
	{
		if (a[i]/n>2)
			flag=1;
		if (a[i]/n>=2)
			tot+=a[i]/n;
	}
	if (tot>=m && (flag || m%2==0))
	{
		cout<<"Yes"<<endl;
		return ;
	}
	flag=0;
	tot=0;
	for (int i=1;i<=k;i++)
	{
		if (a[i]/m>2)
			flag=1;
		if (a[i]/m>=2)
			tot+=a[i]/m;
	}
	if (tot>=n && (flag || n%2==0))
	{
		cout<<"Yes"<<endl;
		return ;
	}
	cout<<"No"<<endl;

}

int main()
{
	int casenum=1;
	cin>>casenum;
	for (int testcase=1;testcase<=casenum;testcase++)
		work();
	return 0;
}
