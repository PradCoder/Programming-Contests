#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
int read(){
	char c=getchar();int x=0;
	while(c<48||c>57) c=getchar();
	do x=(x<<1)+(x<<3)+(c^48),c=getchar();
	while(c>=48&&c<=57);
	return x;
}
const int _=100003;
typedef unsigned long long ull;
const ull D=1000000007;
int a[_][5],w[_],p[_];
ull b[_][32];
int n,m;
unordered_map<ull,int> c;
bool cmp(const int i,const int j){return w[i]<w[j];}
void ins(int i){for(int s=1;s<(1<<m);++s) ++c[b[p[i]][s]];}
void del(int i){for(int s=1;s<(1<<m);++s) --c[b[p[i]][s]];}
int calc(int i){
	int r=0;
	for(int s=1;s<(1<<m);++s)
		if(__builtin_parity(s)) r+=c[b[p[i]][s]];
		else r-=c[b[p[i]][s]];
	return r;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j) a[i][j]=read();
		sort(a[i],a[i]+m);
		for(int s=1;s<(1<<m);++s){
			int pr=1;b[i][s]=0;
			for(int j=0;j<m;++j)
				if(s>>j&1){
					b[i][s]=b[i][s]*D+(a[i][j]-pr+1);
					pr=a[i][j];
				}
		}
		w[p[i]=i]=read();
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;++i) ins(i);
	int mx=n,res=0x7fffffff;
	for(int i=1;i<=mx;++i){
		bool fl=0;
		del(i);
		while(calc(i)<mx-i) del(mx--),fl=1;
		if(fl) ins(++mx),res=min(res,w[p[i]]+w[p[mx]]);
	}
	if(res==0x7fffffff) puts("-1");
	else printf("%d\n",res);
	return 0;
}
