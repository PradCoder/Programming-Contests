//cses WorkFile
//Input and output
//compile using: g++ -std=c++11 -O2 -Wall test.cpp -o test
#include <bits/stdc++.h>

using namespace std;

//to remove bottlenecks
ios::sync_with_stdio(0);
cin.tie(0);

int main(){
    
    //solution comes here
    int a,b;
    string x;
    cin >> a >> b >> x;
}

//for scanning input using C methods
int a,b;
scanf("%d %d\n",a,b);

//for printing statements using C methods
int a = 123, b = 456;
printf("%d %d\n", a, b);

//gets an entire line
string s;
getline(cin, s);

//gets unspecified amount of input
while (cin >> x){

}

//for file I/O using std streams (to be added to beginning of code)
freopen("input.txt",'r',stdin);
freopen("output.txt",'w',stdout);

//for 64 bit numbers
long long x = 64LL;

//for 128 bit numbers
__int128_t x = 128;

//long long x = 1
long long x = 1;
for (int i = 2; i <= n; i++){
    x = (x*i)%m; 
}
cout << x%m << "\n";

//get modulo from the lowest (most negative) multiple of m
x = x%m;
if (x < 0) x += m;

//floating point numbers
/*
64-bit double
80-bit long double
*/
printf(%.9f\n,x);

double x = 0.3*3+0.1;
printf("%.20f\n",x);// 0.999999

//for comaparing floating point numbers if they are equal
//because of precision errors
if(abs(a-b)<1e-9){
    //
}

//to shorten code use typedef
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;//this is good if I'm not using pi

//to shorten code use Macros
#define F first
#define S second
#define PB push_back
#define MP make_pair

//Before shortening
v.push_back(make_pair(y1,x1));
v.push_back(make_pair(y2,x2));
int d = v[i].first+[i].second;

//After shortening
v.PB(MP(y1,x1));
v.PB(MP(y2,x2));
int d = v[i].F+v[i].S;

#define REP(i,a,b) for (int i=a; i<=b; i++)

//Before shortening
for (int i = a; i <= b; i++){
    search(i);
}

//After shortening
REP(i,1,n){
    search(i);
}

//Macros can cause bugs so be careful to follow the 
//order of operations
#define SQ(a) (a)*(a)

/*
for sum of degree 1 use n*(n+1)/2
for sum of degree 2 use n*(n+1)*(2n+1)/(2*3)
for sum of arithmentic series n*(a+b)/2 where a is first number
and b is last number and n is the number of numbers
The sum of a geometric progression (bk-a)/(k-1)
the upper bound for harmonic sums can be shown to be
logbase2(n)+1
*/

/*
set theory (dope stuff)
A intersects B
A union B
A complement
A difference B - (A\B): elements in a and not in B
*/

/*
--Logic--
The value of a logical expression is either true or false
The most important logical operators are 
negation, conjunction, disjunction, implication, and equivalence

A predicate is an expression that is true or false depending on 
its parameters. Predicates are usually denoted by capital letters.

A quantifier connects a logical expression to the elements of a set.
The most important quantifiers are (for all) and (there is)
*/

/*
The number of digits of integer x in base b is floor(logb(x)+1)
*/
