/*
Finding the maximum sum of a subarray in 
different complexities 
in 
O(n^3)
O(n^2)
O(n)
*/
//O(n^3)
#include <bits/stdc++.h>

using namespace std;

int main(){

ios::sync_with_stdio(0);
cin.tie(0);

int best = 0;
for (int a = 0; a < n; a++){
    for (int b = a; a < n; b++){
        int sum = 0;
        for(int k =a; k<=b; k++){
            sum+=array[k]
        }
        best = max(best,sum)
    }
}
cout << best << "\n";
//O(n^2)
int best = 0;
for (int a = 0; a < n; a++){
    int sum = 0;
    for (int b = a; b<n;b++){
        sum+=array[b];
        best = max(best,sum);
    }
}
cout << best << "\n";
//O(n)
//Kadane's algorithms - the most efficient 
int best = 0, sum = 0;
for (int k = 0; k < n ;k++){
    sum += max(array[k],sum+array[k]);
    best = max(best,sum)
}
cout << best << "\n";
}

//bubble sort algorithm with swap
for(int i = 0; i<n;i++){
    for(int j = 0; j<n-1;j++){
        if(array[j]>array[j+1){
            swap(array[j],array[j+1]);
        }
    }
}
// gives position and * grabs value at that position
void swap(int* array[j],int* array[j+1]){
    int temp = *array[j];
    *array[j] = *array[j+1];
    *array[j+1] = temp;
}

//implementations of a sort in c++
vector<int> v = {4,2,5,3,5,8,3};
//asscending
sort(v.begin,v.end());
//descending
sort(v.rbegin(),v.rend());

int n = 7;//array size
int a[] = {4,2,5,3,5,8,3};
sort( a, a+n);

string s = "monkey";
sort(s.begin(),s.end());

//making and sorting pairs
vector<pair<int,int>> v;
v.push_back({1,5});
v.push_back({2,3});
v.push_back({1,2});
sort(v.begin(),v.end());

//making and sorting tuples
//Note: older compilers use make_tuple instead of {}
vector <tuple<int,int,int>> v;
v.push_back({2,1,4});
v.push_back({1,5,3});
v.push_back({2,1,3});
sort(v.begin(), v.end());

//Structs and making operators using operator<
struct P {
    int x, y;
    bool operator<(const P &p){
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

//external comparison functions
bool comp(string a, string b){
    if(a.size() !=b.size()) return a.size() < b.size();
    return a<b;
}
sort(v.begin,v.end(), comp);

for (int i = 0; i < n; i++){
    if(array[i] == x){
        // x found at index i
    }
}

//binary search - only for sorted arrays
//O(log n) - imagine how you'd look for a word in the dictionary
/*
Binary search could be made more efficient if the loop is broken 
when the target element is found.
*/
int a = 0, b = n-1;
    while(a<=b){
        int k= (a+b)/2;
        if(array[k] == x){
            //x found at index k
        }
        //notice single line no brackets comparisons
        if(array[k]>x) b = k-1;
        else a = k+1;
    }

//another binary search method based 
//on a more efficent traversal of the array 
int k = 0;
for(int b = n/2; b >=1 ; b/=2){
    while (k+b<n && array[k+b] <= x) k += b;
}
if(array[k] == x){
    //x found at index k
}

//C++ functions from standard library
//the functions assume that the array is sorted
//if there are no elements that meet the criteria then the pointer goes 
//to the next element after the array
/*Note: auto is used to declare a complex type*/
auto k = lower_bound(array,array+n,x)-array;
if(k<n && array[k] == x){
    //x found at index k
}

//The following code gives the differences between the address that 
//contain elements below x and above x (essentially providing with 
//us the number of x's)
auto a = lower_bound(array, array+n, x);
auto b = upper_bound((array, array+n, x);
cout << b-a <<"\n";

//The equal_range function includes upper and lower bound
auto r = equal_range(array, array+n, x);
cout << r.second-r.first <<"\n";

int x = -1;//it's negative 1 here because you need to do addition for
           //comparsion in the first place, and you look at future values

           //ok is a given function in the problem
for (int b = z; b >= 1; b /= 2){
    while(!ok(x+b)) x += b;
}
int k = x+1;//undoes -1

//Binary search can be used to find the maximum of a function that is
//increasing or decreasing
/*Note in this case consecutive values for the function
cannot be equal otherewise the search will not yield correct results*/
int x = -1;
for (int b = z; b>=1; b/=2){
    while(f(x+b) < f(x+b+1)) x += b;
}
int k = x+1;//you look at future values for passes until b=1 thus
            //the one is added (to include 0 and cancel -1)
